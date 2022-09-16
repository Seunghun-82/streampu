#include "Module/Probe/Latency/Probe_latency.hpp"

using namespace aff3ct;
using namespace aff3ct::module;

template <typename T>
Probe_latency<T>
::Probe_latency(const int size, const std::string &col_name, tools::Reporter_probe& reporter, const int n_frames)
: Probe<T>(size, col_name, reporter, n_frames),
  t_start(std::chrono::steady_clock::now())
{
	const std::string name = "Probe_latency<" + col_name + ">";
	this->set_name(name);
	this->set_single_wave(true);
}

template <typename T>
void Probe_latency<T>
::_probe(const T *in, const size_t frame_id)
{
	auto t_stop = std::chrono::steady_clock::now();
	auto time_duration = (int64_t)std::chrono::duration_cast<std::chrono::microseconds>(t_stop - this->t_start).count();
	this->t_start = t_stop;

	for (size_t f = 0; f < this->get_n_frames(); f++)
		this->reporter.probe(this->col_name, (void*)&time_duration, frame_id);
}

template <typename T>
std::type_index Probe_latency<T>
::get_datatype() const
{
	return typeid(int64_t);
}

template <typename T>
void Probe_latency<T>
::reset()
{
	this->t_start = std::chrono::steady_clock::now();
}

// ==================================================================================== explicit template instantiation
template class aff3ct::module::Probe_latency<int8_t>;
template class aff3ct::module::Probe_latency<uint8_t>;
template class aff3ct::module::Probe_latency<int16_t>;
template class aff3ct::module::Probe_latency<uint16_t>;
template class aff3ct::module::Probe_latency<int32_t>;
template class aff3ct::module::Probe_latency<uint32_t>;
template class aff3ct::module::Probe_latency<int64_t>;
template class aff3ct::module::Probe_latency<uint64_t>;
template class aff3ct::module::Probe_latency<float>;
template class aff3ct::module::Probe_latency<double>;
// ==================================================================================== explicit template instantiation
