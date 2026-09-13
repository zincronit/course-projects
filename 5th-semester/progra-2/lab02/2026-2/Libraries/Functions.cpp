//
// Created by zincronit on 9/12/26.
//

#include "Functions.hpp"

void open_input_file(std::ifstream& fin, const char* filepath)
{
    fin.open(filepath);
    if (not fin.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

void open_output_file(std::ofstream& fout, const char* filepath)
{
    fout.open(filepath);
    if (not fout.is_open())
    {
        std::cout << "Error opening file " << filepath << std::endl;
        std::exit(1);
    }
}

int read_int(std::ifstream& fin, bool can_read)
{
    int value;
    fin >> value;
    if (can_read) fin.get();
    return value;
}

double read_double(std::ifstream& fin, bool can_read)
{
    double value;
    fin >> value;
    if (can_read) fin.get();
    return value;
}

char* allocate_string(const char* text)
{
    char* string = new char[std::strlen(text) + 1];
    std::strcpy(string, text);
    return string;
}

char* read_string(std::ifstream& fin, char character)
{
    char* string;
    char buffer[TEXT_LENGTH];
    fin.getline(buffer, TEXT_LENGTH, character);
    if (fin.eof()) return nullptr;
    string = allocate_string(buffer);
    return string;
}

void print_text(std::ofstream& fout, const char* text, int width, bool should_align_right)
{
    fout << std::left;
    if (should_align_right) fout << std::right;
    fout << std::setw(width) << text;
}

void print_line(std::ofstream& fout, int width, char character)
{
    for (int i = 0; i < width; i++) fout.put(character);
    fout << std::endl;
}

void load_sales(const char* filepath, char***& sales)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    char** buffer[MAX_SALE]{};
    int count = 0;
    while (true)
    {
        // V00001,C0277,2026-07-07,WEB
        buffer[count] = read_sale(fin);
        if (fin.eof()) break;
        ++count;
    }
    sales = new char **[count + 1]{};
    for (int i = 0; i < count; i++)
    {
        sales[i] = buffer[i];
    }
    fin.close();
}

char** read_sale(std::ifstream& fin)
{
    char** aux = new char *[4]{};
    char* code;
    code = read_string(fin);
    if (fin.eof()) return nullptr;
    aux[0] = code;
    aux[1] = read_string(fin);
    aux[2] = read_string(fin);
    aux[3] = read_string(fin, '\n');
    return aux;
}

void load_sale_detail(const char* filepath, char*** sales, char****& text_data, int***& int_data)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    int size = get_sale_size(sales);
    text_data = new char ***[size + 1]{};
    int_data = new int **[size + 1]{};
    int count[MAX_SALE]{}, capacity[MAX_SALE]{}, index;
    char* sale_code;
    while (true)
    {
        // V00097,P0106,UNIDAD,1,12,0%
        sale_code = read_string(fin);
        if (fin.eof())
        {
            delete sale_code;
            break;
        }
        // fin.ignore(100, '\n');
        index = find_sale_index(sales, sale_code);
        if (index == NOT_FOUND)
        {
            fin.ignore(100, '\n');
            continue;
        }
        if (count[index] >= capacity[index] - 1)
            append_data_capacity(
                text_data[index],
                int_data[index],
                capacity[index],
                count[index]
            );
        insert_data(fin, text_data[index], int_data[index], count[index]);
        delete sale_code;
    }
    fin.close();
}

int get_sale_size(char*** sales)
{
    int count = 0;
    for (int i = 0; sales[i] != nullptr; i++) count++;
    return count;
}

int find_sale_index(char*** sales, char* sale_code)
{
    for (int i = 0; sales[i] != nullptr; i++)
    {
        char** aux = sales[i];
        if (std::strcmp(aux[0], sale_code) == 0) return i;
    }
    return NOT_FOUND;
}

void append_data_capacity(char***& text_data, int**& int_data, int& capacity, int count)
{
    capacity += INCREASE;
    char*** aux_char = new char **[capacity]{};
    int** aux_int = new int *[capacity]{};
    if (capacity == INCREASE)
    {
        text_data = aux_char;
        int_data = aux_int;
        return;
    }
    for (int i = 0; i < count; i++)
    {
        aux_char[i] = text_data[i];
        aux_int[i] = int_data[i];
    }
    delete[] text_data;
    delete[] int_data;
    int_data = aux_int;
    text_data = aux_char;
}

void insert_data(std::ifstream& fin, char*** text_data, int** int_data, int& count)
{
    // V00097,P0106,UNIDAD,1,12,0%
    char** aux_char = new char *[4]{};
    int* aux_int = new int[5]{};
    aux_char[0] = read_string(fin);
    aux_char[1] = read_string(fin);
    aux_int[0] = read_int(fin);
    aux_int[1] = read_int(fin);
    aux_int[2] = read_int(fin);

    text_data[count] = aux_char;
    int_data[count] = aux_int;
    fin.get();
    count++;
}

void complete_data_detail(const char* filepath, char**** text_data, int*** int_data)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    char *product_code, *description, *category;
    int cost, price;
    while (true)
    {
        // P0001,Avena Pacifico Tipo 17,ABARROTES,22,25
        product_code = read_string(fin);
        if (fin.eof())
        {
            delete product_code;
            break;
        }
        description = read_string(fin);
        category = read_string(fin);
        cost = read_int(fin);
        price = read_int(fin);
        read_product(text_data, int_data, product_code, description, category, cost, price);
        delete product_code;
        delete description;
        delete category;
    }
    fin.close();
}

void read_product(char**** text_data,
                  int*** int_data,
                  char* code,
                  char* description,
                  char* category,
                  int cost,
                  int price)
{
    for (int i = 0; text_data[i] != nullptr; i++)
    {
        char*** aux_char = text_data[i];
        int** aux_int = int_data[i];
        for (int j = 0; aux_char[j] != nullptr; j++)
        {
            char** buffer_char = aux_char[j];
            int* buffer_int = aux_int[j];
            if (std::strcmp(buffer_char[0], code) == 0)
            {
                buffer_char[2] = allocate_string(description);
                buffer_char[3] = allocate_string(category);
                buffer_int[3] = cost;
                buffer_int[4] = price;
            }
        }
    }
}


void print_report(const char* filepath, char*** sales, char**** text_data, int*** int_data, bool has_products)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    print_title(fout);
    double total_cost = 0;
    double total_price = 0;
    double total_win = 0;
    for (int i = 0; sales[i] != nullptr; i++)
    {
        print_sale_detail(fout, sales[i]);
        if (has_products)
        {
            print_header_products(fout);
            print_products(fout, text_data[i], int_data[i], total_cost, total_price);
            print_statistics(fout , total_cost, total_price , total_win );
        }
    }
    fout.close();
}

void print_title(std::ofstream& fout)
{
    char title[] = "PackMart S.A.";
    char subtitle[] = "REGISTRO DE VETAS";
    print_text(fout, title, (std::strlen(title) + LINE_WIDTH) / 2, true);
    fout << std::endl;
    print_text(fout, subtitle, (std::strlen(subtitle) + LINE_WIDTH) / 2, true);
    fout << std::endl;
    print_line(fout);
}

void print_sale_detail(std::ofstream& fout, char** sale)
{
    int width = LINE_WIDTH / 4;
    print_text(fout, "CODIGO DE VENTAS", width);
    print_text(fout, "CODIGO DEL CLIENTE", width);
    print_text(fout, "FECHA DE VENTA", width);
    print_text(fout, "CATNAL DE VENTA", width);
    fout << std::endl;
    fout << std::setw(width) << sale[0] << std::setw(width) << sale[1];
    fout << std::setw(width) << sale[2] << std::setw(width) << sale[3];
    fout << std::endl;
    print_line(fout , LINE_WIDTH ,'-');
}

void print_header_products(std::ofstream& fout)
{
    int width = LINE_WIDTH / COLUMNS;
    fout << "PRODUCTOS COMPRADOS: \n";
    print_text(fout, "CODIGO", width - 12);
    print_text(fout, "DESCRIPCION", width - 4);
    print_text(fout, "PRESENTACION", width + 10);
    print_text(fout, "CATEGORIA", width - 4);
    print_text(fout, "UNID X PRES", width);
    print_text(fout, "CANTIDAD", width);
    print_text(fout, "COSTO UNIT", width);
    print_text(fout, "PRECIO UNIT", width);
    print_text(fout, "DESCUENTO", width);
    fout <<std::endl;
}
void print_products(std::ofstream& fout, char*** text_data,int** int_data, double& total_cost, double& total_price)
{
    int width = LINE_WIDTH / COLUMNS;
    for (int i = 0; text_data[i] != nullptr; i++)
    {
        char** aux_char = text_data[i];
        int* aux_int = int_data[i];
        fout << std::setw(width - 12) << aux_char[0] << std::setw(width - 4) << aux_char[1];
        fout << std::setw(width + 10) << aux_char[2] << std::setw(width) << aux_char[3];
        fout << std::setw(width) << aux_int[0] << std::setw(width) << aux_int[1];
        fout << std::setw(width) << aux_int[2] << std::setw(width) << aux_int[3];
        fout << std::setw(width) << aux_int[4] << std::endl;
        total_cost += aux_int[3];
        total_price += (double)aux_int[4]*(100 - aux_int[2])/100;
    }
    print_line(fout, LINE_WIDTH, '-');
}
void print_statistics(std::ofstream& fout, double& total_cost, double& total_price, double total_win)
{
    fout << std::fixed << std::setprecision(2);
    total_win = total_price - total_cost;
    print_text(fout , "COSTO TOTAL",50 );
    fout << total_cost << std::endl;
    print_text(fout , "PRECIO TOTAL",50 );
    fout << total_price << std::endl;
    print_text(fout , "GANANCIA TOTAL",50 );
    fout << total_win << std::endl;
    print_line(fout);

}