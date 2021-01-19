char* to_string_RU_million_plus(char *str_in)
{
    char *str_out = malloc(sizeof(char) * 100);
    if (strlen(str_in) > 2)
    {
        switch (str_in[strlen(str_in) - 3])
        {
            case '9':
            {
                strncat(str_out, "Девятьсот ", strlen("Девятьсот "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Восемьсот ", strlen("Восемьсот "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Семьсот ", strlen("Семьсот "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Шестьсот ", strlen("Шестьсот "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Пятьсот ", strlen("Пятьсот "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Четыреста ", strlen("Четыреста "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Триста ", strlen("Триста "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Двести ", strlen("Двести "));
                break;
            }
            case '1':
            {
                strncat(str_out, "Сто ", strlen("Сто "));
                break;
            }
            default:
            {
                break;
            }
        }
    }


    int fl_ten = 0;

    if (strlen(str_in) > 1)
    {
        switch (str_in[strlen(str_in) - 2])
        {
            case '9':
            {
                strncat(str_out, "Девяноста ", strlen("Девяноста "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Восемьдесят ", strlen("Восемьдесят "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Семьдесят ", strlen("Семьдесят "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Шестьдесят ", strlen("Шестьдесят "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Пятьдесят ", strlen("Пятьдесят "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Сорок ", strlen("Сорок "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Тридцать ", strlen("Тридцать "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Двадцать ", strlen("Двадцать "));
                break;
            }
            case '1':
            {
                fl_ten++;
                switch (str_in[strlen(str_in) - 1])
                {
                    case '9':
                    {
                        strncat(str_out, "Девятнадцать ", strlen("Девятнадцать "));
                        break;
                    }
                    case '8':
                    {
                        strncat(str_out, "Восемнадцать ", strlen("Восемнадцать "));
                        break;
                    }
                    case '7':
                    {
                        strncat(str_out, "Семнадцать ", strlen("Семнадцать "));
                        break;
                    }
                    case '6':
                    {
                        strncat(str_out, "Шестнадцать ", strlen("Шестнадцать "));
                        break;
                    }
                    case '5':
                    {
                        strncat(str_out, "Пятнадцать ", strlen("Пятнадцать "));
                        break;
                    }
                    case '4':
                    {
                        strncat(str_out, "Четырнадцать ", strlen("Четырнадцать "));
                        break;
                    }
                    case '3':
                    {
                        strncat(str_out, "Тринадцать ", strlen("Тринадцать "));
                        break;
                    }
                    case '2':
                    {
                        strncat(str_out, "Двенадцать ", strlen("Двенадцать "));
                        break;
                    }
                    case '1':
                    {
                        strncat(str_out, "Одиннадцать ", strlen("Одиннадцать "));
                        break;
                    }
                    case '0':
                    {
                        strncat(str_out, "Десять ", strlen("Десять "));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            default:
            {
                break;
            }
        }
    }

    if (fl_ten == 0)
    {
        switch (str_in[strlen(str_in) - 1])
        {
            case '9':
            {
                strncat(str_out, "Девять ", strlen("Девять "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Восемь ", strlen("Восемь "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Семь ", strlen("Семь "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Шесть ", strlen("Шесть "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Пять ", strlen("Пять "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Четыре ", strlen("Четыре "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Три ", strlen("Три "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Два ", strlen("Два "));
                break;
            }
            case '1':
            {
                strncat(str_out, "Один ", strlen("Один "));
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return str_out;

}

char* to_string_RU_tis(char *str_in)
{
    char *str_out = malloc(sizeof(char) * 100);
    if (strlen(str_in) > 2)
    {
        switch (str_in[strlen(str_in) - 3])
        {
            case '9':
            {
                strncat(str_out, "Девятьсот ", strlen("Девятьсот "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Восемьсот ", strlen("Восемьсот "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Семьсот ", strlen("Семьсот "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Шестьсот ", strlen("Шестьсот "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Пятьсот ", strlen("Пятьсот "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Четыреста ", strlen("Четыреста "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Триста ", strlen("Триста "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Двести ", strlen("Двести "));
                break;
            }
            case '1':
            {
                strncat(str_out, "Сто ", strlen("Сто "));
                break;
            }
            default:
            {
                break;
            }
        }
    }


    int fl_ten = 0;

    if (strlen(str_in) > 1)
    {
        switch (str_in[strlen(str_in) - 2])
        {
            case '9':
            {
                strncat(str_out, "Девяноста ", strlen("Девяноста "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Восемьдесят ", strlen("Восемьдесят "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Семьдесят ", strlen("Семьдесят "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Шестьдесят ", strlen("Шестьдесят "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Пятьдесят ", strlen("Пятьдесят "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Сорок ", strlen("Сорок "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Тридцать ", strlen("Тридцать "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Двадцать ", strlen("Двадцать "));
                break;
            }
            case '1':
            {
                fl_ten++;
                switch (str_in[strlen(str_in) - 1])
                {
                    case '9':
                    {
                        strncat(str_out, "Девятнадцать ", strlen("Девятнадцать "));
                        break;
                    }
                    case '8':
                    {
                        strncat(str_out, "Восемнадцать ", strlen("Восемнадцать "));
                        break;
                    }
                    case '7':
                    {
                        strncat(str_out, "Семнадцать ", strlen("Семнадцать "));
                        break;
                    }
                    case '6':
                    {
                        strncat(str_out, "Шестнадцать ", strlen("Шестнадцать "));
                        break;
                    }
                    case '5':
                    {
                        strncat(str_out, "Пятнадцать ", strlen("Пятнадцать "));
                        break;
                    }
                    case '4':
                    {
                        strncat(str_out, "Четырнадцать ", strlen("Четырнадцать "));
                        break;
                    }
                    case '3':
                    {
                        strncat(str_out, "Тринадцать ", strlen("Тринадцать "));
                        break;
                    }
                    case '2':
                    {
                        strncat(str_out, "Двенадцать ", strlen("Двенадцать "));
                        break;
                    }
                    case '1':
                    {
                        strncat(str_out, "Одиннадцать ", strlen("Одиннадцать "));
                        break;
                    }
                    case '0':
                    {
                        strncat(str_out, "Десять ", strlen("Десять "));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            default:
            {
                break;
            }
        }
    }

    if (fl_ten == 0)
    {
        switch (str_in[strlen(str_in) - 1])
        {
            case '9':
            {
                strncat(str_out, "Девять ", strlen("Девять "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Восемь ", strlen("Восемь "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Семь ", strlen("Семь "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Шесть ", strlen("Шесть "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Пять ", strlen("Пять "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Четыре ", strlen("Четыре "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Три ", strlen("Три "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Две ", strlen("Две "));
                break;
            }
            case '1':
            {
                strncat(str_out, "Одна ", strlen("Одна "));
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return str_out;

}

char* to_string_RU(char *str_in)
{
    char *str_out = malloc(sizeof(char) * 600);
    char *str_in_2 = malloc(sizeof(char) * 100);
    int length = strlen(str_in);
    if (str_in[0] == '-')
    {
        strncat(str_out, "Минус ", strlen("Минус "));
        str_in_2 = &str_in[1];
        length--;
    }
    else
    {
        str_in_2 = str_in;
    }
    if (strlen(str_in_2) > 33)    //дециллион
    {
        char *deci = malloc(sizeof(char) * 5);
        strncat(deci, str_in_2, strlen(str_in_2) - 33);
        char *deci_rez = malloc(sizeof(char) * 100);
        deci_rez = to_string_RU_million_plus(deci);
        if (strlen(deci_rez) != 0)
        {
            strncat(str_out, deci_rez, strlen(deci_rez));
            int deci_fl_na = 0;
            if (strlen(deci) >= 2)
            {
                if ((deci[strlen(deci) - 1] == '1') && (deci[strlen(deci) - 2] != '1'))
                {
                    strncat(str_out, "Дециллион ", strlen("Дециллион "));
                    deci_fl_na++;
                }
                else
                {
                    if ((deci[strlen(deci) - 1] > '0') && (deci[strlen(deci) - 1] < '5') && (deci[strlen(deci) - 2] != '1'))
                    {
                        strncat(str_out, "Дециллиона ", strlen("Дециллиона "));
                        deci_fl_na++;
                    }
                }

            }
            if (strlen(deci) == 1)
            {
                if (deci[strlen(deci) - 1] == '1')
                {
                    strncat(str_out, "Дециллион ", strlen("Дециллион "));
                    deci_fl_na++;
                }
                else
                {
                    if (deci[strlen(deci) - 1] < '5')
                    {
                        strncat(str_out, "Дециллиона ", strlen("Дециллиона "));
                        deci_fl_na++;
                    }
                }
            }
            if (deci_fl_na == 0)
            {
                strncat(str_out, "Дециллионов ", strlen("Дециллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(deci)];
    }

    if (strlen(str_in_2) > 30)    //нониллион
    {
        char *noni = malloc(sizeof(char) * 5);
        strncat(noni, str_in_2, strlen(str_in_2) - 30);
        char *noni_rez = malloc(sizeof(char) * 100);
        noni_rez = to_string_RU_million_plus(noni);
        if (strlen(noni_rez) != 0)
        {
            strncat(str_out, noni_rez, strlen(noni_rez));
            int noni_fl_na = 0;
            if (strlen(noni) >= 2)
            {
                if ((noni[strlen(noni) - 1] == '1') && (noni[strlen(noni) - 2] != '1'))
                {
                    strncat(str_out, "Нониллион ", strlen("Нониллион "));
                    noni_fl_na++;
                }
                else
                {
                    if ((noni[strlen(noni) - 1] < '5') && (noni[strlen(noni) - 1] > '0') && (noni[strlen(noni) - 2] != '1'))
                    {
                        strncat(str_out, "Нониллиона ", strlen("Нониллиона "));
                        noni_fl_na++;
                    }
                }

            }
            if (strlen(noni) == 1)
            {
                if (noni[strlen(noni) - 1] == '1')
                {
                    strncat(str_out, "Нониллион ", strlen("Нониллион "));
                    noni_fl_na++;
                }
                else
                {
                    if (noni[strlen(noni) - 1] < '5')
                    {
                        strncat(str_out, "Нониллиона ", strlen("Нониллиона "));
                        noni_fl_na++;
                    }
                }
            }
            if (noni_fl_na == 0)
            {
                strncat(str_out, "Нониллионов ", strlen("Нониллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(noni)];
    }

    if (strlen(str_in_2) > 27)    //октиллион
    {
        char *octi = malloc(sizeof(char) * 5);
        strncat(octi, str_in_2, strlen(str_in_2) - 27);
        char *octi_rez = malloc(sizeof(char) * 100);
        octi_rez = to_string_RU_million_plus(octi);
        if (strlen(octi_rez) != 0)
        {
            strncat(str_out, octi_rez, strlen(octi_rez));
            int octi_fl_na = 0;
            if (strlen(octi) >= 2)
            {
                if ((octi[strlen(octi) - 1] == '1') && (octi[strlen(octi) - 2] != '1'))
                {
                    strncat(str_out, "Октиллион ", strlen("Октиллион "));
                    octi_fl_na++;
                }
                else
                {
                    if ((octi[strlen(octi) - 1] < '5') && (octi[strlen(octi) - 1] > '0') && (octi[strlen(octi) - 2] != '1'))
                    {
                        strncat(str_out, "Октиллиона ", strlen("Октиллиона "));
                        octi_fl_na++;
                    }
                }

            }
            if (strlen(octi) == 1)
            {
                if (octi[strlen(octi) - 1] == '1')
                {
                    strncat(str_out, "Октиллион ", strlen("Октиллион "));
                    octi_fl_na++;
                }
                else
                {
                    if (octi[strlen(octi) - 1] < '5')
                    {
                        strncat(str_out, "Октиллиона ", strlen("Октиллиона "));
                        octi_fl_na++;
                    }
                }
            }
            if (octi_fl_na == 0)
            {
                strncat(str_out, "Октиллионов ", strlen("Октиллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(octi)];
    }

    if (strlen(str_in_2) > 24)    //септиллион
    {
        char *septi = malloc(sizeof(char) * 5);
        strncat(septi, str_in_2, strlen(str_in_2) - 24);
        char *septi_rez = malloc(sizeof(char) * 100);
        septi_rez = to_string_RU_million_plus(septi);
        if (strlen(septi_rez) != 0)
        {
            strncat(str_out, septi_rez, strlen(septi_rez));
            int septi_fl_na = 0;
            if (strlen(septi) >= 2)
            {
                if ((septi[strlen(septi) - 1] == '1') && (septi[strlen(septi) - 2] != '1'))
                {
                    strncat(str_out, "Септиллион ", strlen("Септиллион "));
                    septi_fl_na++;
                }
                else
                {
                    if ((septi[strlen(septi) - 1] < '5') && (septi[strlen(septi) - 1] > '0') && (septi[strlen(septi) - 2] != '1'))
                    {
                        strncat(str_out, "Септиллиона ", strlen("Септиллиона "));
                        septi_fl_na++;
                    }
                }

            }
            if (strlen(septi) == 1)
            {
                if (septi[strlen(septi) - 1] == '1')
                {
                    strncat(str_out, "Септиллион ", strlen("Септиллион "));
                    septi_fl_na++;
                }
                else
                {
                    if (septi[strlen(septi) - 1] < '5')
                    {
                        strncat(str_out, "Септиллиона ", strlen("Септиллиона "));
                        septi_fl_na++;
                    }
                }
            }
            if (septi_fl_na == 0)
            {
                strncat(str_out, "Септиллионов ", strlen("Септиллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(septi)];
    }

    if (strlen(str_in_2) > 21)    //секстиллион
    {
        char *sexti = malloc(sizeof(char) * 5);
        strncat(sexti, str_in_2, strlen(str_in_2) - 21);
        char *sexti_rez = malloc(sizeof(char) * 100);
        sexti_rez = to_string_RU_million_plus(sexti);
        if (strlen(sexti_rez) != 0)
        {
            strncat(str_out, sexti_rez, strlen(sexti_rez));
            int sexti_fl_na = 0;
            if (strlen(sexti) >= 2)
            {
                if ((sexti[strlen(sexti) - 1] == '1') && (sexti[strlen(sexti) - 2] != '1'))
                {
                    strncat(str_out, "Секстиллион ", strlen("Секстиллион "));
                    sexti_fl_na++;
                }
                else
                {
                    if ((sexti[strlen(sexti) - 1] < '5') && (sexti[strlen(sexti) - 1] > '0') && (sexti[strlen(sexti) - 2] != '1'))
                    {
                        strncat(str_out, "Секстиллиона ", strlen("Секстиллиона "));
                        sexti_fl_na++;
                    }
                }

            }
            if (strlen(sexti) == 1)
            {
                if (sexti[strlen(sexti) - 1] == '1')
                {
                    strncat(str_out, "Секстиллион ", strlen("Секстиллион "));
                    sexti_fl_na++;
                }
                else
                {
                    if (sexti[strlen(sexti) - 1] < '5')
                    {
                        strncat(str_out, "Секстиллиона ", strlen("Секстиллиона "));
                        sexti_fl_na++;
                    }
                }
            }
            if (sexti_fl_na == 0)
            {
                strncat(str_out, "Секстиллионов ", strlen("Секстиллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(sexti)];
    }

    if (strlen(str_in_2) > 18)    //квинтиллион
    {
        char *kvinti = malloc(sizeof(char) * 5);
        strncat(kvinti, str_in_2, strlen(str_in_2) - 18);
        char *kvinti_rez = malloc(sizeof(char) * 100);
        kvinti_rez = to_string_RU_million_plus(kvinti);
        if (strlen(kvinti_rez) != 0)
        {
            strncat(str_out, kvinti_rez, strlen(kvinti_rez));
            int kvinti_fl_na = 0;
            if (strlen(kvinti) >= 2)
            {
                if ((kvinti[strlen(kvinti) - 1] == '1') && (kvinti[strlen(kvinti) - 2] != '1'))
                {
                    strncat(str_out, "Квинтиллион ", strlen("Квинтиллион "));
                    kvinti_fl_na++;
                }
                else
                {
                    if ((kvinti[strlen(kvinti) - 1] < '5') && (kvinti[strlen(kvinti) - 1] > '0') && (kvinti[strlen(kvinti) - 2] != '1'))
                    {
                        strncat(str_out, "Квинтиллиона ", strlen("Квинтиллиона "));
                        kvinti_fl_na++;
                    }
                }

            }
            if (strlen(kvinti) == 1)
            {
                if (kvinti[strlen(kvinti) - 1] == '1')
                {
                    strncat(str_out, "Квинтиллион ", strlen("Квинтиллион "));
                    kvinti_fl_na++;
                }
                else
                {
                    if (kvinti[strlen(kvinti) - 1] < '5')
                    {
                        strncat(str_out, "Квинтиллиона ", strlen("Квинтиллиона "));
                        kvinti_fl_na++;
                    }
                }
            }
            if (kvinti_fl_na == 0)
            {
                strncat(str_out, "Квинтиллионов ", strlen("Квинтиллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(kvinti)];
    }

    if (strlen(str_in_2) > 15)    //квадриллион
    {
        char *kvadri = malloc(sizeof(char) * 5);
        strncat(kvadri, str_in_2, strlen(str_in_2) - 15);
        char *kvadri_rez = malloc(sizeof(char) * 100);
        kvadri_rez = to_string_RU_million_plus(kvadri);
        if (strlen(kvadri_rez) != 0)
        {
            strncat(str_out, kvadri_rez, strlen(kvadri_rez));
            int kvadri_fl_na = 0;
            if (strlen(kvadri) >= 2)
            {
                if ((kvadri[strlen(kvadri) - 1] == '1') && (kvadri[strlen(kvadri) - 2] != '1'))
                {
                    strncat(str_out, "Квадриллион ", strlen("Квадриллион "));
                    kvadri_fl_na++;
                }
                else
                {
                    if ((kvadri[strlen(kvadri) - 1] < '5') && (kvadri[strlen(kvadri) - 1] > '0') && (kvadri[strlen(kvadri) - 2] != '1'))
                    {
                        strncat(str_out, "Квадриллиона ", strlen("Квадриллиона "));
                        kvadri_fl_na++;
                    }
                }

            }
            if (strlen(kvadri) == 1)
            {
                if (kvadri[strlen(kvadri) - 1] == '1')
                {
                    strncat(str_out, "Квадриллион ", strlen("Квадриллион "));
                    kvadri_fl_na++;
                }
                else
                {
                    if (kvadri[strlen(kvadri) - 1] < '5')
                    {
                        strncat(str_out, "Квадриллиона ", strlen("Квадриллиона "));
                        kvadri_fl_na++;
                    }
                }
            }
            if (kvadri_fl_na == 0)
            {
                strncat(str_out, "Квадриллионов ", strlen("Квадриллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(kvadri)];
    }

    if (strlen(str_in_2) > 12)    //триллион
    {
        char *tri = malloc(sizeof(char) * 5);
        strncat(tri, str_in_2, strlen(str_in_2) - 12);
        char *tri_rez = malloc(sizeof(char) * 100);
        tri_rez = to_string_RU_million_plus(tri);
        if (strlen(tri_rez) != 0)
        {
            strncat(str_out, tri_rez, strlen(tri_rez));
            int tri_fl_na = 0;
            if (strlen(tri) >= 2)
            {
                if ((tri[strlen(tri) - 1] == '1') && (tri[strlen(tri) - 2] != '1'))
                {
                    strncat(str_out, "Триллион ", strlen("Триллион "));
                    tri_fl_na++;
                }
                else
                {
                    if ((tri[strlen(tri) - 1] < '5') && (tri[strlen(tri) - 1] > '0') && (tri[strlen(tri) - 2] != '1'))
                    {
                        strncat(str_out, "Триллиона ", strlen("Триллиона "));
                        tri_fl_na++;
                    }
                }

            }
            if (strlen(tri) == 1)
            {
                if (tri[strlen(tri) - 1] == '1')
                {
                    strncat(str_out, "Триллион ", strlen("Триллион "));
                    tri_fl_na++;
                }
                else
                {
                    if (tri[strlen(tri) - 1] < '5')
                    {
                        strncat(str_out, "Триллиона ", strlen("Триллиона "));
                        tri_fl_na++;
                    }
                }
            }
            if (tri_fl_na == 0)
            {
                strncat(str_out, "Триллионов ", strlen("Триллионов "));
            }
        }

        str_in_2 = &str_in_2[strlen(tri)];
    }

    if (strlen(str_in_2) > 9)    //миллиард
    {
        char *milli = malloc(sizeof(char) * 5);
        strncat(milli, str_in_2, strlen(str_in_2) - 9);
        char *milli_rez = malloc(sizeof(char) * 100);
        milli_rez = to_string_RU_million_plus(milli);
        if (strlen(milli_rez) != 0)
        {
            strncat(str_out, milli_rez, strlen(milli_rez));
            int milli_fl_na = 0;
            if (strlen(milli) >= 2)
            {
                if ((milli[strlen(milli) - 1] == '1') && (milli[strlen(milli) - 2] != '1'))
                {
                    strncat(str_out, "Миллиард ", strlen("Миллиард "));
                    milli_fl_na++;
                }
                else
                {
                    if ((milli[strlen(milli) - 1] < '5') && (milli[strlen(milli) - 1] > '0') && (milli[strlen(milli) - 2] != '1'))
                    {
                        strncat(str_out, "Миллиарда ", strlen("Миллиарда "));
                        milli_fl_na++;
                    }
                }

            }
            if (strlen(milli) == 1)
            {
                if (milli[strlen(milli) - 1] == '1')
                {
                    strncat(str_out, "Миллиард ", strlen("Миллиард "));
                    milli_fl_na++;
                }
                else
                {
                    if (milli[strlen(milli) - 1] < '5')
                    {
                        strncat(str_out, "Миллиарда ", strlen("Миллиарда "));
                        milli_fl_na++;
                    }
                }
            }
            if (milli_fl_na == 0)
            {
                strncat(str_out, "Миллиардов ", strlen("Миллиардов "));
            }
        }

        str_in_2 = &str_in_2[strlen(milli)];
    }

    if (strlen(str_in_2) > 6)    //миллион
    {
        char *mil = malloc(sizeof(char) * 5);
        strncat(mil, str_in_2, strlen(str_in_2) - 6);
        char *mil_rez = malloc(sizeof(char) * 100);
        mil_rez = to_string_RU_million_plus(mil);
        if (strlen(mil_rez) != 0)
        {
            strncat(str_out, mil_rez, strlen(mil_rez));
            int mil_fl_na = 0;
            if (strlen(mil) >= 2)
            {
                if ((mil[strlen(mil) - 1] == '1') && (mil[strlen(mil) - 2] != '1'))
                {
                    strncat(str_out, "Миллион ", strlen("Миллион "));
                    mil_fl_na++;
                }
                else
                {
                    if ((mil[strlen(mil) - 1] < '5') && (mil[strlen(mil) - 1] > '0') && (mil[strlen(mil) - 2] != '1'))
                    {
                        strncat(str_out, "Миллиона ", strlen("Миллиона "));
                        mil_fl_na++;
                    }
                }

            }
            if (strlen(mil) == 1)
            {
                if (mil[strlen(mil) - 1] == '1')
                {
                    strncat(str_out, "Миллион ", strlen("Миллион "));
                    mil_fl_na++;
                }
                else
                {
                    if (mil[strlen(mil) - 1] < '5')
                    {
                        strncat(str_out, "Миллиона ", strlen("Миллиона "));
                        mil_fl_na++;
                    }
                }
            }
            if (mil_fl_na == 0)
            {
                strncat(str_out, "Миллионов ", strlen("Миллионов "));
            }

        }
        str_in_2 = &str_in_2[strlen(mil)];
    }

    if (strlen(str_in_2) > 3)    //тысяча
    {
        char *tis = malloc(sizeof(char) * 5);
        strncat(tis, str_in_2, strlen(str_in_2) - 3);
        char *tis_rez = malloc(sizeof(char) * 100);
        tis_rez = to_string_RU_tis(tis);
        if (strlen(tis_rez) != 0)
        {
            strncat(str_out, tis_rez, strlen(tis_rez));
            int tis_fl_na = 0;
            if (strlen(tis) >= 2)
            {
                if ((tis[strlen(tis) - 1] == '1') && (tis[strlen(tis) - 2] != '1'))
                {
                    strncat(str_out, "Тысяча ", strlen("Тысяча "));
                    tis_fl_na++;
                }
                else
                {
                    if ((tis[strlen(tis) - 1] < '5') && (tis[strlen(tis) - 1] > '0') && (tis[strlen(tis) - 2] != '1'))
                    {
                        strncat(str_out, "Тысячи ", strlen("Тысячи "));
                        tis_fl_na++;
                    }
                }

            }
            if (strlen(tis) == 1)
            {
                if (tis[strlen(tis) - 1] == '1')
                {
                    strncat(str_out, "Тысяча ", strlen("Тысяча "));
                    tis_fl_na++;
                }
                else
                {
                    if (tis[strlen(tis) - 1] < '5')
                    {
                        strncat(str_out, "Тысячи ", strlen("Тысячи "));
                        tis_fl_na++;
                    }
                }
            }
            if (tis_fl_na == 0)
            {
                strncat(str_out, "Тысяч ", strlen("Тысяч "));
            }

        }
        str_in_2 = &str_in_2[strlen(tis)];
    }

    if (strlen(str_in_2) > 0)    //сотня
    {
        char *sot = malloc(sizeof(char) * 5);
        strncat(sot, str_in_2, strlen(str_in_2) - 0);
        char *sot_rez = malloc(sizeof(char) * 100);
        sot_rez = to_string_RU_million_plus(sot);
        strncat(str_out, sot_rez, strlen(sot_rez));
    }

    return str_out;
}

char* to_string_EN_million_plus(char *str_in)
{
    char *str_out = malloc(sizeof(char) * 100);
    if (strlen(str_in) > 2)
    {
        switch (str_in[strlen(str_in) - 3])
        {
            case '9':
            {
                strncat(str_out, "Nine Hundred ", strlen("Nine Hundred "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Eight Hundred ", strlen("Eight Hundred "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Seven Hundred ", strlen("Seven Hundred "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Six Hundred ", strlen("Six Hundred "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Five Hundred ", strlen("Five Hundred "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Four Hundred ", strlen("Four Hundred "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Three Hundred ", strlen("Three Hundred "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Two Hundred ", strlen("Two Hundred "));
                break;
            }
            case '1':
            {
                strncat(str_out, "One Hundred ", strlen("One Hundred "));
                break;
            }
            default:
            {
                break;
            }
        }
    }


    int fl_ten = 0;

    if (strlen(str_in) > 1)
    {
        switch (str_in[strlen(str_in) - 2])
        {
            case '9':
            {
                strncat(str_out, "Ninety ", strlen("Ninety "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Eighty ", strlen("Eighty "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Seventy ", strlen("Seventy "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Sixty ", strlen("Sixty "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Fifty ", strlen("Fifty "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Forty ", strlen("Forty "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Thirty ", strlen("Thirty "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Twenty ", strlen("Twenty "));
                break;
            }
            case '1':
            {
                fl_ten++;
                switch (str_in[strlen(str_in) - 1])
                {
                    case '9':
                    {
                        strncat(str_out, "Nineteen ", strlen("Nineteen "));
                        break;
                    }
                    case '8':
                    {
                        strncat(str_out, "Eighteen ", strlen("Eighteen "));
                        break;
                    }
                    case '7':
                    {
                        strncat(str_out, "Seventeen ", strlen("Seventeen "));
                        break;
                    }
                    case '6':
                    {
                        strncat(str_out, "Sixteen ", strlen("Sixteen "));
                        break;
                    }
                    case '5':
                    {
                        strncat(str_out, "Fifteen ", strlen("Fifteen "));
                        break;
                    }
                    case '4':
                    {
                        strncat(str_out, "Fourteen ", strlen("Fourteen "));
                        break;
                    }
                    case '3':
                    {
                        strncat(str_out, "Thirteen ", strlen("Thirteen "));
                        break;
                    }
                    case '2':
                    {
                        strncat(str_out, "Twelve ", strlen("Twelve "));
                        break;
                    }
                    case '1':
                    {
                        strncat(str_out, "Eleven ", strlen("Eleven "));
                        break;
                    }
                    case '0':
                    {
                        strncat(str_out, "Ten ", strlen("Ten "));
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            default:
            {
                break;
            }
        }
    }

    if (fl_ten == 0)
    {
        switch (str_in[strlen(str_in) - 1])
        {
            case '9':
            {
                strncat(str_out, "Nine ", strlen("Nine "));
                break;
            }
            case '8':
            {
                strncat(str_out, "Eight ", strlen("Eight "));
                break;
            }
            case '7':
            {
                strncat(str_out, "Seven ", strlen("Seven "));
                break;
            }
            case '6':
            {
                strncat(str_out, "Six ", strlen("Six "));
                break;
            }
            case '5':
            {
                strncat(str_out, "Five ", strlen("Five "));
                break;
            }
            case '4':
            {
                strncat(str_out, "Four ", strlen("Four "));
                break;
            }
            case '3':
            {
                strncat(str_out, "Three ", strlen("Three "));
                break;
            }
            case '2':
            {
                strncat(str_out, "Two ", strlen("Two "));
                break;
            }
            case '1':
            {
                strncat(str_out, "One ", strlen("One "));
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return str_out;

}

char* to_string_EN(char *str_in)
{
    char *str_out = malloc(sizeof(char) * 600);
    char *str_in_2 = malloc(sizeof(char) * 100);
    int length = strlen(str_in);
    if (str_in[0] == '-')
    {
        strncat(str_out, "Minus ", strlen("Minus "));
        str_in_2 = &str_in[1];
        length--;
    }
    else
    {
        str_in_2 = str_in;
    }
    if (strlen(str_in_2) > 33)    //дециллион
    {
        char *deci = malloc(sizeof(char) * 5);
        strncat(deci, str_in_2, strlen(str_in_2) - 33);
        char *deci_rez = malloc(sizeof(char) * 100);
        deci_rez = to_string_EN_million_plus(deci);
        if (strlen(deci_rez) != 0)
        {
            strncat(str_out, deci_rez, strlen(deci_rez));
            strncat(str_out, "Decillion ", strlen("Decillion "));
        }
        str_in_2 = &str_in_2[strlen(deci)];
    }

    if (strlen(str_in_2) > 30)    //нониллион
    {
        char *noni = malloc(sizeof(char) * 5);
        strncat(noni, str_in_2, strlen(str_in_2) - 30);
        char *noni_rez = malloc(sizeof(char) * 100);
        noni_rez = to_string_EN_million_plus(noni);
        if (strlen(noni_rez) != 0)
        {
            strncat(str_out, noni_rez, strlen(noni_rez));
            strncat(str_out, "Nonillion ", strlen("Nonillion "));
        }
        str_in_2 = &str_in_2[strlen(noni)];
    }

    if (strlen(str_in_2) > 27)    //октиллион
    {
        char *octi = malloc(sizeof(char) * 5);
        strncat(octi, str_in_2, strlen(str_in_2) - 27);
        char *octi_rez = malloc(sizeof(char) * 100);
        octi_rez = to_string_EN_million_plus(octi);
        if (strlen(octi_rez) != 0)
        {
            strncat(str_out, octi_rez, strlen(octi_rez));
            strncat(str_out, "Octillion ", strlen("Octillion "));
        }
        str_in_2 = &str_in_2[strlen(octi)];
    }

    if (strlen(str_in_2) > 24)    //септиллион
    {
        char *septi = malloc(sizeof(char) * 5);
        strncat(septi, str_in_2, strlen(str_in_2) - 24);
        char *septi_rez = malloc(sizeof(char) * 100);
        septi_rez = to_string_EN_million_plus(septi);
        if (strlen(septi_rez) != 0)
        {
            strncat(str_out, septi_rez, strlen(septi_rez));
            strncat(str_out, "Septillion ", strlen("Septillion "));
        }
        str_in_2 = &str_in_2[strlen(septi)];
    }

    if (strlen(str_in_2) > 21)    //секстиллион
    {
        char *sexti = malloc(sizeof(char) * 5);
        strncat(sexti, str_in_2, strlen(str_in_2) - 21);
        char *sexti_rez = malloc(sizeof(char) * 100);
        sexti_rez = to_string_EN_million_plus(sexti);
        if (strlen(sexti_rez) != 0)
        {
            strncat(str_out, sexti_rez, strlen(sexti_rez));
            strncat(str_out, "Sextillion ", strlen("Sextillion "));
        }
        str_in_2 = &str_in_2[strlen(sexti)];
    }

    if (strlen(str_in_2) > 18)    //квинтиллион
    {
        char *kvinti = malloc(sizeof(char) * 5);
        strncat(kvinti, str_in_2, strlen(str_in_2) - 18);
        char *kvinti_rez = malloc(sizeof(char) * 100);
        kvinti_rez = to_string_EN_million_plus(kvinti);
        if (strlen(kvinti_rez) != 0)
        {
            strncat(str_out, kvinti_rez, strlen(kvinti_rez));
            strncat(str_out, "Quintillion ", strlen("Quintillion "));
        }
        str_in_2 = &str_in_2[strlen(kvinti)];
    }

    if (strlen(str_in_2) > 15)    //квадриллион
    {
        char *kvadri = malloc(sizeof(char) * 5);
        strncat(kvadri, str_in_2, strlen(str_in_2) - 15);
        char *kvadri_rez = malloc(sizeof(char) * 100);
        kvadri_rez = to_string_EN_million_plus(kvadri);
        if (strlen(kvadri_rez) != 0)
        {
            strncat(str_out, kvadri_rez, strlen(kvadri_rez));
            strncat(str_out, "Quadrillion ", strlen("Quadrillion "));
        }
        str_in_2 = &str_in_2[strlen(kvadri)];
    }

    if (strlen(str_in_2) > 12)    //триллион
    {
        char *tri = malloc(sizeof(char) * 5);
        strncat(tri, str_in_2, strlen(str_in_2) - 12);
        char *tri_rez = malloc(sizeof(char) * 100);
        tri_rez = to_string_EN_million_plus(tri);
        if (strlen(tri_rez) != 0)
        {
            strncat(str_out, tri_rez, strlen(tri_rez));
            strncat(str_out, "Trillion ", strlen("Trillion "));
        }
        str_in_2 = &str_in_2[strlen(tri)];
    }

    if (strlen(str_in_2) > 9)    //миллиард
    {
        char *milli = malloc(sizeof(char) * 5);
        strncat(milli, str_in_2, strlen(str_in_2) - 9);
        char *milli_rez = malloc(sizeof(char) * 100);
        milli_rez = to_string_EN_million_plus(milli);
        if (strlen(milli_rez) != 0)
        {
            strncat(str_out, milli_rez, strlen(milli_rez));
            strncat(str_out, "Billion ", strlen("Billion "));
        }
        str_in_2 = &str_in_2[strlen(milli)];
    }

    if (strlen(str_in_2) > 6)    //миллион
    {
        char *mil = malloc(sizeof(char) * 5);
        strncat(mil, str_in_2, strlen(str_in_2) - 6);
        char *mil_rez = malloc(sizeof(char) * 100);
        mil_rez = to_string_EN_million_plus(mil);
        if (strlen(mil_rez) != 0)
        {
            strncat(str_out, mil_rez, strlen(mil_rez));
            strncat(str_out, "Million ", strlen("Million "));
        }
        str_in_2 = &str_in_2[strlen(mil)];
    }

    if (strlen(str_in_2) > 3)    //тысяча
    {
        char *tis = malloc(sizeof(char) * 5);
        strncat(tis, str_in_2, strlen(str_in_2) - 3);
        char *tis_rez = malloc(sizeof(char) * 100);
        tis_rez = to_string_EN_million_plus(tis);
        if (strlen(tis_rez) != 0)
        {
            strncat(str_out, tis_rez, strlen(tis_rez));
            strncat(str_out, "Thousand ", strlen("Thousand "));
        }
        str_in_2 = &str_in_2[strlen(tis)];
    }

    if (strlen(str_in_2) > 0)    //сотня
    {
        char *sot = malloc(sizeof(char) * 5);
        strncat(sot, str_in_2, strlen(str_in_2) - 0);
        char *sot_rez = malloc(sizeof(char) * 100);
        sot_rez = to_string_EN_million_plus(sot);
        strncat(str_out, sot_rez, strlen(sot_rez));
    }

    return str_out;
}