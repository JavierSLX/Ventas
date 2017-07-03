#include "stdafx.h"  //_____________________________________________ GraficoVentas.cpp
#include "GraficoVentas.h"

void GraficoVentas::Window_Open(Win::Event& e)
{
	//________________________________________________________ tabVenta
	tabVenta.Items.Add(0, L"Pastel");
	tabVenta.Items.Add(1, L"Barras");
	
	//________________________________________________________ piePastel
	piePastel.Pies.Add(L"Adult", RGB(250, 70, 70), 200.0);
	piePastel.Pies.Add(L"Children", RGB(70, 70, 250), 100.0);
	piePastel.Pies.Add(L"Teens", RGB(70, 250, 70), 50.0);
	//________________________________________________________ bchartBarras
	bchartBarras.Bars.Add(L"May", RGB(230, 50, 50), 20.0);
	bchartBarras.Bars.Add(L"June", RGB(50, 230, 50), 40.0);
	bchartBarras.Bars.Add(L"July", RGB(50, 50, 230), 80.0);
	bchartBarras.MaxY = 100.0;
	bchartBarras.Text = L"Sales";

	//Hace invisible la gráfica de barras
	bchartBarras.Visible = false;
}


//Cuando cambia la tab
void GraficoVentas::tabVenta_SelChange(Win::Event& e)
{
	if (tabVenta.GetSelectedIndex() == 0)
	{
		piePastel.Visible = true;
		bchartBarras.Visible = false;
	}
	else
	{
		piePastel.Visible = false;
		bchartBarras.Visible = true;
	}
}

