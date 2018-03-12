#ifndef LAB_H
#define LAB_H


class lab
{
public:
    lab();
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    int Getdate_id()
    {
        return date_id;
    }
    void Setdate_id(int val)
    {
        date_id = val;
    }
    bool Getavaliable()
    {
        return avaliable;
    }
    void Setavaliable(bool val)
    {
        avaliable = val;
    }
    int Getdoctor_id()
    {
        return doctor_id;
    }
    void Setdoctor_id(int val)
    {
        doctor_id = val;
    }
protected:
private:
    int id;
    int date_id;
    bool avaliable;
    int doctor_id;
};

#endif // LAB_H
