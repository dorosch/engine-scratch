#include "model.hpp"


Model::Model(std::string file_path) {
    Model::_file_path = file_path;
}


void Model::load() {
    std::string line;
    std::ifstream file(Model::_file_path);

    if (file.is_open() == false) {
        std::cerr <<
            "Error render model: " << Model::_file_path << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        char type;
        std::string x, y, z;
        std::stringstream string(line);

        if (line.rfind("v ", 0) == false) {
            Vector v;

            string >> type >> x >> y >> z;

            v.x = std::stof(x);
            v.y = std::stof(y);
            v.z = std::stof(z);

            Model::_vertices.push_back(v);
        }

        if (line.rfind("f ", 0) == false) {
            int index[3];
            char separator = '/';
            std::string a;

            string >> type >> x >> y >> z;

            std::stringstream facet_x(x);
            std::getline(facet_x, a, separator);
            index[0] = std::stoi(a) - 1;

            std::stringstream facet_y(y);
            std::getline(facet_y, a, separator);
            index[1] = std::stoi(a) - 1;

            std::stringstream facet_z(z);
            std::getline(facet_z, a, separator);
            index[2] = std::stoi(a) - 1;

            Model::facets.push_back({
                Model::_vertices[index[0]],
                Model::_vertices[index[1]],
                Model::_vertices[index[2]],
            });
        }
    }
}
