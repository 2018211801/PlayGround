package cn.edu.bupt.ch9_1;

        import org.springframework.data.domain.Page;
        import org.springframework.data.domain.Pageable;
        import org.springframework.data.jpa.repository.JpaRepository;
        import org.springframework.data.repository.CrudRepository;
        import org.springframework.data.repository.PagingAndSortingRepository;

        import java.util.List;

public interface CustomerRepository extends PagingAndSortingRepository<Customer, Long> {

        List<Customer> findByLastName(String lastName);
        Page<Customer> findAllByFirstName(String firstName, Pageable pageable);
        Customer findById(long id);
}
