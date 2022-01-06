//* 2.39 *//
//struct Foo { /*empty*/ } // Note: no semicolon
//int main()
//{
//	return 0;
//}

#include <iostream>
#include <string>

//* 2.40 *//
struct sales_data {
	std::string isbn;
	unsigned booksSold = 0;
	double revenue = 0.0;
};

int main() {

	// 2.41 rewrite the previous exercises using the new sales data struct
	/*
	Exercise 1.20: http://www.informit.com/title/032174113 contains a copy of
	Sales_item.h in the Chapter 1 code directory. Copy that file to your
	working directory. Use it to write a program that reads a set of book sales
	transactions, writing each transaction to the standard output.
	Exercise 1.21: Write a program that reads two Sales_item objects that
	have the same ISBN and produces their sum.
	Exercise 1.22: Write a program that reads several transactions for the same
	ISBN. Write the sum of all the transactions that were read.
	*/
	sales_data SalesData, TotalData;
	std::string tmp_isbn;
	while (std::cin >> SalesData.isbn >> SalesData.booksSold >> SalesData.revenue) {
		if (tmp_isbn == "") {
			TotalData.booksSold += SalesData.booksSold;
			TotalData.revenue += SalesData.revenue;
		}
		else {
			if (tmp_isbn != SalesData.isbn) {
				std::cerr << "ISBNs do not match";
				return -1;
			}
			else {
				TotalData.booksSold += SalesData.booksSold;
				TotalData.revenue += SalesData.revenue;
			}
			
		}
		tmp_isbn = SalesData.isbn;
	}
	std::cout << TotalData.booksSold << " " << TotalData.revenue << std::endl;


	/*
	Exercise 1.23: Write a program that reads several transactions and counts
	how many transactions occur for each ISBN.
	Exercise 1.24: Test the previous program by giving multiple transactions
	representing multiple ISBNs. The records for each ISBN should be grouped
	together.
	*/
	unsigned cnt = 0;
	while (std::cin >> SalesData.isbn >> SalesData.booksSold >> SalesData.revenue) {
		if (tmp_isbn == "") {
			cnt++;
		}
		else {
			if (tmp_isbn != SalesData.isbn) {
				std::cout << tmp_isbn << " occurred " << cnt << " times!" << std::endl;
				cnt = 0;
			}
			else {
				cnt++;
			}

		}
		tmp_isbn = SalesData.isbn;
	}
	std::cout << TotalData.booksSold << " " << TotalData.revenue << std::endl;
	return 0;
}

int main()
{
	sales_data total; // variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	if (std::cin >> total.isbn >> total.booksSold >> total.revenue) {
		sales_data trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (std::cin >> trans.isbn >> trans.booksSold >> trans.revenue) {
			// if we're still processing the same book
			if (total.isbn == trans.isbn)
				total.revenue += trans.revenue; // update the running total
			else {
				// print results for the previous book
				std::cout << total.revenue << std::endl;
				total.isbn = trans.isbn; // total now refers to the next book

			}
		}
		std::cout << total.isbn << total.booksSold << total.revenue << std::endl; // print the last transaction
	}
	else {
		// no input! warn the user
		std::cerr << "No data?!" << std::endl;
		return -1; // indicate failure
	}

		return 0;
}