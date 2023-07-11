
// Code generated by stanc v2.29.0
#include <stan/model/model_header.hpp>
namespace test_model_namespace {

using stan::model::model_base_crtp;
using namespace stan::math;


stan::math::profile_map profiles__;
static constexpr std::array<const char*, 20> locations_array__ = 
{" (found before start of program)",
 " (in '/home/DA/project/test.stan', line 8, column 2 to column 22)",
 " (in '/home/DA/project/test.stan', line 9, column 2 to column 13)",
 " (in '/home/DA/project/test.stan', line 10, column 2 to column 22)",
 " (in '/home/DA/project/test.stan', line 11, column 2 to column 22)",
 " (in '/home/DA/project/test.stan', line 24, column 2 to column 24)",
 " (in '/home/DA/project/test.stan', line 27, column 4 to column 56)",
 " (in '/home/DA/project/test.stan', line 28, column 4 to column 41)",
 " (in '/home/DA/project/test.stan', line 26, column 17 to line 29, column 3)",
 " (in '/home/DA/project/test.stan', line 26, column 2 to line 29, column 3)",
 " (in '/home/DA/project/test.stan', line 17, column 2 to column 30)",
 " (in '/home/DA/project/test.stan', line 18, column 2 to column 30)",
 " (in '/home/DA/project/test.stan', line 19, column 2 to column 24)",
 " (in '/home/DA/project/test.stan', line 20, column 2 to column 24)",
 " (in '/home/DA/project/test.stan', line 2, column 2 to column 17)",
 " (in '/home/DA/project/test.stan', line 3, column 9 to column 10)",
 " (in '/home/DA/project/test.stan', line 3, column 2 to column 15)",
 " (in '/home/DA/project/test.stan', line 4, column 9 to column 10)",
 " (in '/home/DA/project/test.stan', line 4, column 2 to column 15)",
 " (in '/home/DA/project/test.stan', line 24, column 9 to column 10)"};




class test_model final : public model_base_crtp<test_model> {

 private:
  int N;
  Eigen::Matrix<double, -1, 1> x1__;
  Eigen::Matrix<double, -1, 1> x2__; 
  Eigen::Map<Eigen::Matrix<double, -1, 1>> x1{nullptr, 0};
  Eigen::Map<Eigen::Matrix<double, -1, 1>> x2{nullptr, 0};
 
 public:
  ~test_model() { }
  
  inline std::string model_name() const final { return "test_model"; }

  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.29.0", "stancflags = "};
  }
  
  
  test_model(stan::io::var_context& context__,
             unsigned int random_seed__ = 0,
             std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    int current_statement__ = 0;
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static constexpr const char* function__ = "test_model_namespace::test_model";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      current_statement__ = 14;
      context__.validate_dims("data initialization","N","int",
           std::vector<size_t>{});
      N = std::numeric_limits<int>::min();
      
      
      current_statement__ = 14;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 14;
      stan::math::check_greater_or_equal(function__, "N", N, 0);
      current_statement__ = 15;
      stan::math::validate_non_negative_index("x1", "N", N);
      current_statement__ = 16;
      context__.validate_dims("data initialization","x1","double",
           std::vector<size_t>{static_cast<size_t>(N)});
      x1__ = 
        Eigen::Matrix<double, -1, 1>::Constant(N,
          std::numeric_limits<double>::quiet_NaN());
      new (&x1) Eigen::Map<Eigen::Matrix<double, -1, 1>>(x1__.data(), N);
      
      {
        std::vector<local_scalar_t__> x1_flat__;
        current_statement__ = 16;
        x1_flat__ = context__.vals_r("x1");
        current_statement__ = 16;
        pos__ = 1;
        current_statement__ = 16;
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          current_statement__ = 16;
          stan::model::assign(x1, x1_flat__[(pos__ - 1)],
            "assigning variable x1", stan::model::index_uni(sym1__));
          current_statement__ = 16;
          pos__ = (pos__ + 1);
        }
      }
      current_statement__ = 17;
      stan::math::validate_non_negative_index("x2", "N", N);
      current_statement__ = 18;
      context__.validate_dims("data initialization","x2","double",
           std::vector<size_t>{static_cast<size_t>(N)});
      x2__ = 
        Eigen::Matrix<double, -1, 1>::Constant(N,
          std::numeric_limits<double>::quiet_NaN());
      new (&x2) Eigen::Map<Eigen::Matrix<double, -1, 1>>(x2__.data(), N);
      
      {
        std::vector<local_scalar_t__> x2_flat__;
        current_statement__ = 18;
        x2_flat__ = context__.vals_r("x2");
        current_statement__ = 18;
        pos__ = 1;
        current_statement__ = 18;
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          current_statement__ = 18;
          stan::model::assign(x2, x2_flat__[(pos__ - 1)],
            "assigning variable x2", stan::model::index_uni(sym1__));
          current_statement__ = 18;
          pos__ = (pos__ + 1);
        }
      }
      current_statement__ = 19;
      stan::math::validate_non_negative_index("y_generated", "N", N);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    num_params_r__ = 1 + 1 + 1 + 1;
    
  }
  
  template <bool propto__, bool jacobian__ , typename VecR, typename VecI, 
  stan::require_vector_like_t<VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "test_model_namespace::log_prob";
    (void) function__;  // suppress unused var warning
    
    try {
      local_scalar_t__ alpha = DUMMY_VAR__;
      current_statement__ = 1;
      alpha = in__.template read_constrain_lb<local_scalar_t__, jacobian__>(
                0, lp__);
      local_scalar_t__ beta1 = DUMMY_VAR__;
      current_statement__ = 2;
      beta1 = in__.template read<local_scalar_t__>();
      local_scalar_t__ beta2 = DUMMY_VAR__;
      current_statement__ = 3;
      beta2 = in__.template read_constrain_lb<local_scalar_t__, jacobian__>(
                0, lp__);
      local_scalar_t__ sigma = DUMMY_VAR__;
      current_statement__ = 4;
      sigma = in__.template read_constrain_lb<local_scalar_t__, jacobian__>(
                0, lp__);
      {
        current_statement__ = 10;
        lp_accum__.add(stan::math::cauchy_lpdf<propto__>(alpha, 10000, 8000));
        current_statement__ = 11;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(beta1, -0.17, 0.05));
        current_statement__ = 12;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(beta2, 20, 5));
        current_statement__ = 13;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(sigma, 0, 10));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, 
  stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, 
  stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr> 
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    static constexpr bool propto__ = true;
    (void) propto__;
    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    int current_statement__ = 0; 
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    constexpr bool jacobian__ = false;
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "test_model_namespace::write_array";
    (void) function__;  // suppress unused var warning
    
    try {
      double alpha = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 1;
      alpha = in__.template read_constrain_lb<local_scalar_t__, jacobian__>(
                0, lp__);
      double beta1 = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 2;
      beta1 = in__.template read<local_scalar_t__>();
      double beta2 = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 3;
      beta2 = in__.template read_constrain_lb<local_scalar_t__, jacobian__>(
                0, lp__);
      double sigma = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 4;
      sigma = in__.template read_constrain_lb<local_scalar_t__, jacobian__>(
                0, lp__);
      out__.write(alpha);
      out__.write(beta1);
      out__.write(beta2);
      out__.write(sigma);
      if (stan::math::logical_negation((stan::math::primitive_value(
            emit_transformed_parameters__) || stan::math::primitive_value(
            emit_generated_quantities__)))) {
        return ;
      } 
      if (stan::math::logical_negation(emit_generated_quantities__)) {
        return ;
      } 
      Eigen::Matrix<double, -1, 1> y_generated =
         Eigen::Matrix<double, -1, 1>::Constant(N,
           std::numeric_limits<double>::quiet_NaN());
      current_statement__ = 9;
      for (int i = 1; i <= N; ++i) {
        double lambda = std::numeric_limits<double>::quiet_NaN();
        current_statement__ = 6;
        lambda = ((alpha +
                    (beta1 *
                      stan::model::rvalue(x1, "x1",
                        stan::model::index_uni(i)))) +
                   (beta2 *
                     stan::model::rvalue(x2, "x2", stan::model::index_uni(i))));
        current_statement__ = 7;
        stan::model::assign(y_generated,
          stan::math::poisson_rng(lambda, base_rng__),
          "assigning variable y_generated", stan::model::index_uni(i));
      }
      out__.write(y_generated);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, 
  stan::require_std_vector_t<VecVar>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline void transform_inits_impl(VecVar& params_r__, VecI& params_i__,
                                   VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      local_scalar_t__ alpha = DUMMY_VAR__;
      alpha = in__.read<local_scalar_t__>();
      out__.write_free_lb(0, alpha);
      local_scalar_t__ beta1 = DUMMY_VAR__;
      beta1 = in__.read<local_scalar_t__>();
      out__.write(beta1);
      local_scalar_t__ beta2 = DUMMY_VAR__;
      beta2 = in__.read<local_scalar_t__>();
      out__.write_free_lb(0, beta2);
      local_scalar_t__ sigma = DUMMY_VAR__;
      sigma = in__.read<local_scalar_t__>();
      out__.write_free_lb(0, sigma);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__ = std::vector<std::string>{"alpha", "beta1", "beta2", "sigma",
      "y_generated"};
    
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    
    dimss__ = std::vector<std::vector<size_t>>{std::vector<size_t>{},
      std::vector<size_t>{}, std::vector<size_t>{}, std::vector<size_t>{
      }, std::vector<size_t>{static_cast<size_t>(N)}};
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "alpha");
    param_names__.emplace_back(std::string() + "beta1");
    param_names__.emplace_back(std::string() + "beta2");
    param_names__.emplace_back(std::string() + "sigma");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "y_generated" + '.' + std::to_string(sym1__));
        } 
      }
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "alpha");
    param_names__.emplace_back(std::string() + "beta1");
    param_names__.emplace_back(std::string() + "beta2");
    param_names__.emplace_back(std::string() + "sigma");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "y_generated" + '.' + std::to_string(sym1__));
        } 
      }
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"alpha\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"beta1\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"beta2\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"sigma\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"y_generated\",\"type\":{\"name\":\"vector\",\"length\":" + std::to_string(N) + "},\"block\":\"generated_quantities\"}]");
    
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"alpha\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"beta1\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"beta2\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"sigma\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"y_generated\",\"type\":{\"name\":\"vector\",\"length\":" + std::to_string(N) + "},\"block\":\"generated_quantities\"}]");
    
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 
  (((1 + 1) + 1) + 1);
      const size_t num_transformed = 0;
      const size_t num_gen_quantities = N;
      std::vector<double> vars_vec(num_params__
       + (emit_transformed_parameters * num_transformed)
       + (emit_generated_quantities * num_gen_quantities));
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        vars_vec.data(), vars_vec.size());
    }

    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 
  (((1 + 1) + 1) + 1);
      const size_t num_transformed = 0;
      const size_t num_gen_quantities = N;
      vars.resize(num_params__
        + (emit_transformed_parameters * num_transformed)
        + (emit_generated_quantities * num_gen_quantities));
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }

    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }


    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits(context, params_i, params_r_vec, pstream);
      params_r = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        params_r_vec.data(), params_r_vec.size());
    }

  inline void transform_inits(const stan::io::var_context& context,
                              std::vector<int>& params_i,
                              std::vector<double>& vars,
                              std::ostream* pstream__ = nullptr) const {
     constexpr std::array<const char*, 4> names__{"alpha", "beta1", "beta2",
      "sigma"};
      const std::array<Eigen::Index, 4> constrain_param_sizes__{1, 1, 1, 1};
      const auto num_constrained_params__ = std::accumulate(
        constrain_param_sizes__.begin(), constrain_param_sizes__.end(), 0);
    
     std::vector<double> params_r_flat__(num_constrained_params__);
     Eigen::Index size_iter__ = 0;
     Eigen::Index flat_iter__ = 0;
     for (auto&& param_name__ : names__) {
       const auto param_vec__ = context.vals_r(param_name__);
       for (Eigen::Index i = 0; i < constrain_param_sizes__[size_iter__]; ++i) {
         params_r_flat__[flat_iter__] = param_vec__[i];
         ++flat_iter__;
       }
       ++size_iter__;
     }
     vars.resize(num_params_r__);
     transform_inits_impl(params_r_flat__, params_i, vars, pstream__);
    } // transform_inits() 
    
};
}
using stan_model = test_model_namespace::test_model;

#ifndef USING_R

// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

stan::math::profile_map& get_stan_profile_data() {
  return test_model_namespace::profiles__;
}

#endif


