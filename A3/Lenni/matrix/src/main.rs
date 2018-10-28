use std::env;

fn main()
{
    let args: Vec<String> = env::args().collect();
    if args.len() != 4
    {
        panic!("Fuck");
    }

    let mat1: Vec<Vec<i64>> = read_mat(args[1].as_str());
    let mat2: Vec<Vec<i64>> = read_mat(args[3].as_str());
    print_mat(&mat1);
    print!("\n");
    print_mat(&mat2);
    print!("\n");

    let mat3: Vec<Vec<i64>>;

    match args[2].as_str()
    {
        "+" => mat3 = mat_add(&mat1, &mat2),
        "-" => mat3 = mat_sub(&mat1, &mat2),
        _ => panic!("Fuck"),
    }

    print_mat(&mat3);
}

fn read_mat(s: &str) -> Vec<Vec<i64>>
{
    let mut mat: Vec<Vec<i64>> = Vec::new();
    let rows = s.split(";");
    let rows_iter = rows.into_iter().enumerate();
    for (i, r) in rows_iter
    {
        mat.push(Vec::new());
        let col = r.split(",");
        for c in col
        {
            mat[i].push(c.parse::<i64>().unwrap());
        }
    }
    return mat;
}

fn mat_add(m1: &Vec<Vec<i64>>, m2: &Vec<Vec<i64>>) -> Vec<Vec<i64>>
{
    let num_rows = m1.len();
    let num_cols = m1[0].len();
    assert!(num_rows == m2.len() && num_cols == m2[0].len(), "wrong dimensions");

    let mut mat: Vec<Vec<i64>> = Vec::with_capacity(num_rows);

    for i in 0..num_rows
    {
        mat.push(Vec::with_capacity(num_cols));
        for j in 0..num_cols
        {
            mat[i].push(m1[i][j] + m2[i][j]);
        }
    }

    return mat;
}

fn mat_sub(m1: &Vec<Vec<i64>>, m2: &Vec<Vec<i64>>) -> Vec<Vec<i64>>
{
    let num_rows = m1.len();
    let num_cols = m1[0].len();
    assert!(num_rows == m2.len() && num_cols == m2[0].len(), "wrong dimensions");

    let mut mat: Vec<Vec<i64>> = Vec::with_capacity(num_rows);

    for i in 0..num_rows
    {
        mat.push(Vec::with_capacity(num_cols));
        for j in 0..num_cols
        {
            mat[i].push(m1[i][j] - m2[i][j]);
        }
    }

    return mat;
}

fn print_mat(mat: &Vec<Vec<i64>>)
{
    for i in mat
    {
        for j in i
        {
            print!("{} ", j);
        }
        println!("")
    }
}
