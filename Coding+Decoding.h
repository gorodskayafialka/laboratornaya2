#pragma once
std::string coding(Symbol** symbols, std::string to_encode, int& coded_weight, int number_of_symbols);

std::string decoding(Symbol** symbols, std::string coded);
