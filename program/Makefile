PLATEX	= platex
PDFMV	= dvipdfmx
SOURCES:= $(wildcard *.tex)
TARGET	= $(SOURCES:.tex=.pdf)
OBJECTS	= $(SOURCES:.tex=.dvi)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(PDFMV) $<

%.dvi:%.tex
	$(PLATEX) $<

clean:
	$(RM) -r *.aux *.log *.dvi *.pdf
