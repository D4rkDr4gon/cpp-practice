#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Cliente {
    int DNI;
    string nombre;
};

struct TreeNode {
    Cliente cliente;
    TreeNode *left, *right;
};

// Función para crear un nuevo nodo con el valor dado
TreeNode* crearNodo(Cliente valor) {    
    TreeNode* nuevoNodo = new TreeNode;    
    nuevoNodo->cliente = valor;    
    nuevoNodo->left = nullptr;    
    nuevoNodo->right = nullptr;    
    return nuevoNodo;
}

// Función para insertar un nuevo elemento en el árbol binario de búsqueda
TreeNode* insertar(TreeNode* root, Cliente valor) {    
    if (root == nullptr) {        
        return crearNodo(valor); // Si el nodo es nulo, crea un nuevo nodo con el valor dado    
    }        
    // Si el valor es menor que el valor actual, inserta en el subárbol izquierdo    
    if (valor.DNI < root->cliente.DNI) {        
        root->left = insertar(root->left, valor);    
    }    
    // Si el valor es mayor que el valor actual, inserta en el subárbol derecho    
    else if (valor.DNI > root->cliente.DNI) {        
        root->right = insertar(root->right, valor);    
    }        
    return root; // Retorna el nodo raíz actual después de la inserción
}

// Recorrido en inorden de manera recursiva
void inordenRecursivo(TreeNode* root) {    
    if (root == nullptr) {        
        return;    
    }    
    inordenRecursivo(root->left);
    cout << "DNI: " << root->cliente.DNI << " Nombre: " << root->cliente.nombre << endl;    
    inordenRecursivo(root->right);
}

// Función para buscar un cliente por su DNI en el árbol
TreeNode* buscarPorDNI(TreeNode* root, int dni) {
    if (root == nullptr || root->cliente.DNI == dni) {
        return root;
    }
    if (dni < root->cliente.DNI) {
        return buscarPorDNI(root->left, dni);
    }
    return buscarPorDNI(root->right, dni);
}

// Función para encontrar el nodo con el valor mínimo en un subárbol
TreeNode* encontrarMinimo(TreeNode* root) {
    TreeNode* actual = root;
    while (actual->left != nullptr) {
        actual = actual->left;
    }
    return actual;
}

// Función para eliminar un cliente por su DNI del árbol
TreeNode* eliminarPorDNI(TreeNode* root, int dni) {
    if (root == nullptr) {
        return root;
    }
    if (dni < root->cliente.DNI) {
        root->left = eliminarPorDNI(root->left, dni);
    } else if (dni > root->cliente.DNI) {
        root->right = eliminarPorDNI(root->right, dni);
    } else {
        // Nodo con un solo hijo o sin hijos
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Nodo con dos hijos, encontrar el sucesor inorden (nodo más pequeño en el subárbol derecho)
        TreeNode* temp = encontrarMinimo(root->right);
        // Copiar el contenido del sucesor inorden a este nodo
        root->cliente = temp->cliente;
        // Eliminar el sucesor inorden
        root->right = eliminarPorDNI(root->right, temp->cliente.DNI);
    }
    return root;
}



int main() {
    TreeNode* root = nullptr; // Inicializa el árbol binario de búsqueda como vacío

    while (true) {
        int opcion;
        cout << "1. Insertar cliente" << endl;
        cout << "2. Verificar si el arbol esta balanceado" << endl;
        cout << "3. Imprimir arbol" << endl;
        cout << "4. Buscar cliente por DNI" << endl;
        cout << "5. Eliminar cliente por DNI" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Cliente cliente;
            cout << "Ingrese el DNI del cliente: ";
            cin >> cliente.DNI;
            cout << "Ingrese el nombre del cliente: ";
            cin.ignore(); // Ignorar el salto de línea anterior
            getline(cin, cliente.nombre);
            root = insertar(root, cliente);
        } else if (opcion == 2) {
            // Implementa la verificación de balance aquí si lo deseas
        } else if (opcion == 3) { 
            inordenRecursivo(root);
        } else if (opcion == 5) {
            int dni;
            cout << "Ingrese el DNI del cliente que desea eliminar: ";
            cin >> dni;
            root = eliminarPorDNI(root, dni);
        } else if (opcion == 4) {
            int dni;
            cout << "Ingrese el DNI del cliente que desea buscar: ";
            cin >> dni;
            TreeNode* encontrado = buscarPorDNI(root, dni);
            if (encontrado != nullptr) {
                cout << "DNI: " << encontrado->cliente.DNI << " Nombre: " << encontrado->cliente.nombre << endl;
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        } else if (opcion == 6) {
            break;
        } else {
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}
