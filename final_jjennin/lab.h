#ifndef LAB_H
#define LAB_H


class lab
{
public:
    lab();
    int getID()
    {
        return id;
    }
    void setID(int const& val)
    {
        id = val;
    }
    int getDateID()
    {
        return date_id;
    }
    void setDateID(int const& val)
    {
        date_id = val;
    }
    bool Getavaliable()
    {
        return avaliable;
    }
    void Setavaliable(bool const& val)
    {
        avaliable = val;
    }
    int getDoctorID()
    {
        return doctor_id;
    }
    void setDoctorID(int const& val)
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
