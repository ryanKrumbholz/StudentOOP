#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>

class Image {
 public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();

   virtual void display();

    int get_height() { return height; }
    int get_width() { return width; }

 private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};

class Gif : public Image {
    public:
        Gif(int w, int h, std::string flnm) : Image(w,h,flnm){}
        void display();
};

const static int HIGH = 2;
const static int MED = 1;
const static int LOW = 0;

class Jpeg : public Image {
   public:
      Jpeg(int w, int h, std::string flnm, int quality = HIGH) : Image(w, h, flnm) {}
      void display();
};

class Png : public Image {
   public:
      Png (int w, int h, std::string flnm) : Image(w, h, flnm) {}
      void display();
};

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);


class Date {
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
 public:
    Date(int d, int m, int y);
 private:
     int day;
     int month;
     int year;
};


class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws, Image* img) :
        date(dt), temperature(temp), humidity(hum), windspeed(ws), image(img)
    {
    }
   double get_heat_index();
   double get_wind_chill();
   void display_image();
   double get_tempF();
   double get_tempC() { return temperature; }

 private:
   Date date;
   double temperature ;  // stored temp in C
   double humidity;
   double windspeed;
   Image* image;

};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    // << should output name, rating, and use the GPS << to output my_loc
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
    void display_images();

 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif