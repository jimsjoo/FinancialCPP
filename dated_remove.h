
template<class T> void dated<T>::clear() {
  dates_    .erase(dates_    .begin(),dates_    .end());
  elements_ .erase(elements_ .begin(),elements_ .end());
};

template<class T> void dated<T>::remove(const date& d) {
  int i=index_of_date(d);
  if (i>=0) {
    dates_.erase(dates_.begin()+i);
    elements_.erase(elements_.begin()+i);
  };
};

template<class T> void dated<T>::remove_between(const date& d1, const date& d2) {
  if (!d1.valid()) return;
  if (!d2.valid()) return;
  for (int t=size()-1;t>=0;t--){  // this is very slow, to be replaced with one using vector erase.
    date d=date_at(t);
    if ( (d>d1) && (d<d2) ) { 
      dates_.erase(dates_.begin()+t);
      elements_.erase(elements_.begin()+t);
    };
  };
};


template<class T> void dated<T>::remove_between_including_end_points(const date& d1, const date& d2) {
  if (!d1.valid()) return;
  if (!d2.valid()) return;
  for (int t=size()-1;t>=0;t--){  // this is very slow, to be replaced with one using vector erase.
    date d=date_at(t);
    if ( (d>=d1) && (d<=d2) ) { 
      dates_.erase(dates_.begin()+t);
      elements_.erase(elements_.begin()+t);
    };
  };
};

template<class T> void dated<T>::remove_before(const date& d) {
  remove_between(--first_date(),d);
};

template<class T> void dated<T>::remove_after(const date& d) {
  remove_between(d,++last_date());
};

template <class T> ostream& operator << (ostream& outf, const dated<T>& dobs ) {
  if (dobs.empty()) return outf;
  for (int t=0; t<dobs.size(); ++t) {
    outf << dobs.date_at(t) << " "  << dobs.element_at(t)  << endl;
  };
  return outf;
};
