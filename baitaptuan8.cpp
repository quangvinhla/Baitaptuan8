#include <iostream>
using namespace std;

struct Node {
    int coefficient; // hệ số
    int exponent;    // bậc của biến
    Node* next;      // con trỏ tới phần tử tiếp theo
};

Node* createNode(int coefficient, int exponent) {
    Node* newNode = new Node();
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = nullptr;
    return newNode;
}

void addNode(Node*& head, int coefficient, int exponent) {
    if (coefficient == 0) return; // Bỏ qua nếu hệ số bằng 0
    Node* newNode = createNode(coefficient, exponent);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->coefficient << "x^" << temp->exponent;
        if (temp->next) std::cout << " + ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
int main(){
    Node* polynomial = nullptr;
    int n, coefficient, exponent;
    
    std::cout << "Nhap so luong hang tu: ";
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap he so va bac so mu: ";
        std::cin >> coefficient >> exponent;
        addNode(polynomial, coefficient, exponent);
    }
    
    std::cout << "Da thuc vua nhap la: ";
    printPolynomial(polynomial);
    
    return 0;
}