#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

namespace std;

class Product;

class Report {
public:
    virtual string generateProductReport(Product* product) const = 0;
    virtual string generateSalesReport(const string& startDate, const string& endDate) const = 0;
    virtual string generateInventoryReport() const = 0;
    virtual ~Report() {}
};

class ConcreteReport : public Report {
public:
    string generateProductReport(Product* product) const override {
        // Implementation
        return "Product Report";
    }

    string generateSalesReport(const string& startDate, const string& endDate) const override {
        // Implementation
        return "Sales Report";
    }

    string generateInventoryReport() const override {
        // Implementation
        return "Inventory Report";
    }
};

class Customer {
private:
    Customer() = default; // Private constructor
    Customer(const Customer&) = delete;
    Customer& operator=(const Customer&) = delete;
    static unique_ptr<Customer> instance;
    string username;
    string password;
    string email;
    vector<Order> orders;
    vector<Product*> wishlist;

public:
    static Customer& getInstance() {
        if (!instance) {
            instance = make_unique<Customer>();
        }
        return *instance;
    }
    string register(const string& username, const string& password, const string& email);
    bool updateAccountInfo(const map<string, string>& updateData);
    bool managePreferences(const map<string, string>& preferences);
    vector<Order>& getOrders(); 
    vector<Product*>& getWishlist(); 
    ~Customer(){}
};

class Admin {
private:
    Admin() = default; // Private constructor
    Admin(const Admin&) = delete;
    Admin& operator=(const Admin&) = delete;
    static unique_ptr<Admin> instance;
    string username;
    string password;
    string email;
    vector<Order> orders;
    vector<Product*> wishlist;

public:
    static Admin& getInstance() {
        if (!instance) {
            instance = make_unique<Admin>();
        }
        return *instance;
    }

    string createProductListing(Product* product);
    string editProductListing(Product* product);
    bool manageInventory(Product* product, int quantity);
    string createPromotion(Promotion* promotion);
    string viewProductPerformance(Product* product);
    string generateReports(const string& type);
    bool processOrder(Order* order);
    Order* trackOrder(int orderId);

    ~Admin(){}
};

class Seller {
private:
    Seller() = default; // Private constructor
    Seller(const Seller&) = delete;
    Seller& operator=(const Seller&) = delete;

    static unique_ptr<Seller> instance;
    string username;
    string password;
    string email;
    vector<Product> products;

public:
    static Seller& getInstance() {
        if (!instance) {
            instance = make_unique<Seller>();
        }
        return *instance;
    }

    string register(const string& username, const string& password, const string& email);
    vector<Product>& getProducts(); 
    ~Seller(){}
};

class Order {
private:
    int id;
    unique_ptr<Customer> customer;
    vector<OrderItem> items;
    string status;
    Date placedAt;
    Date estimatedDelivery;

public:
    float getTotalPrice() const {
      //Implementation
    }

    Customer* getCustomer() const {
        return customer.get();
    }
};

class OrderItem {
private:
    int id;
    Order* order;
    Product* product;
    int quantity;
    float price;
};

class Product {
private:
    int id;
    std::string name;
    std::string description;
    struct Specifications {
        std::string color;
        std::string size;
        std::string brand;
    } specs;
    float price;
    int stock;
    std::vector<std::string> images;
    std::vector<std::string> videos;
    Seller* seller;

public:
    Product(int id, const std::string& name, const std::string& description,
            const std::string& color, const std::string& size, const std::string& brand,
            float price, int stock,
            const std::vector<std::string>& images, const std::vector<std::string>& videos,
            Seller* seller)
        : id(id), name(name), description(description), specs({color, size, brand}),
          price(price), stock(stock), images(images), videos(videos), seller(seller) {}

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }
    const Specifications& getSpecifications() const { return specs; }
    float getPrice() const { return price; }
    int getStock() const { return stock; }
    const std::vector<std::string>& getImages() const { return images; }
    const std::vector<std::string>& getVideos() const { return videos; }
    Seller* getSeller() const { return seller; }
};


class Promotion {
private:
    int id;
    string type;
    float discount;
    map<string, string> criteria;
    Date startDate;
    Date endDate;

public:
    map<string, string> getDetails() const {
        // Implementation
    }
    ~Promotion() {}
};

int main() {
    // Implementation
    return 0;
}