#ifndef CAPTEURHUMIDITE_H
#define CAPTEURHUMIDITE_H
#define gpio_num_t int


class CapteurHumidite
{
public:
    CapteurHumidite(const gpio_num_t _brocheCapteur);
    int MesurerHumiditeDuSol();
private:
    gpio_num_t brocheCapteur;
};

#endif // CAPTEURHUMIDITE_H
