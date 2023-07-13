vec<ll> dijkstra(vec<vec<pair<ll, ll>>>& v, int s) {
	set<pair<ll, ll>> st;
	st.insert({ 0, s });
	vec<ll> len(v.size(), 1e9);
	len[s] = 0;

	while (st.size() > 0) {
		auto it = st.begin();
		ll l = (*it).first;
		int i = (*it).second;
		st.erase(st.begin());

		for (auto j : v[i]) {
			int nl = l + j.second;
			if (nl < len[j.first]) {
				if (len[j.first] != 1e9) {
					st.erase(st.find({ len[j.first], j.first }));
				}

				len[j.first] = nl;
				st.insert({ len[j.first], j.first });
			}
		}
	}

	re len;
}
