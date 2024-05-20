# 14. Clasificación según la taxonomía de Flynn

### OpenMP: 
Clasificado como SIMD (Single Instruction, Multiple Data) o MIMD (Multiple Instruction, Multiple Data) dependiendo de la implementación específica. Justificación: OpenMP puede ejecutar múltiples threads de forma paralela sobre datos diferentes bajo la misma instrucción (SIMD) o múltiples instrucciones sobre múltiples datos (MIMD).
### MPI: 
Clasificado como MIMD. Justificación: MPI permite a múltiples procesos ejecutarse simultáneamente, cada uno con su propio conjunto de datos y su propia instrucción.
### Multiprocessing: 
Clasificado como MIMD. Justificación: Similar a MPI, multiprocessing en Python permite ejecutar múltiples procesos independientes, cada uno con su propio flujo de instrucciones y datos.