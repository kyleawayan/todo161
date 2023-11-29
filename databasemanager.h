#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

class DatabaseManager
{
public:
    DatabaseManager();
    void openDatabase();
    void closeDatbase();
    bool executeQuery();
private:
    bool checkIfDbExists();
    void createDb();
};

#endif // DATABASEMANAGER_H
