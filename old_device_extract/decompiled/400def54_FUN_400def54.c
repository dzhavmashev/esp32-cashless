// Function : FUN_400def54
// Address  : 0x400def54
// Size     : 62 bytes


void FUN_400def54(int param_1)

{
  if (*(int *)(param_1 + 0x74) != 0) {
    func_0x40091740();
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    func_0x40091740();
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  if (*(int *)(param_1 + 0x78) != 0) {
    func_0x400902dc();
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  *(undefined1 *)(param_1 + 0x30) = 0;
  FUN_400f0780(0x3ffc5490,&DAT_3f406678);
  return;
}

