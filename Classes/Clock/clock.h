class Clock
{
	public:
		Clock();
		void setTime(int, int, int);
		void getTime(int&, int&, int&);
		void printTime();
		void incrementSeconds();
		void incrementMinutes();
		void incrementHours();
	private:
		int hour;
		int minute;
		int second;
};
