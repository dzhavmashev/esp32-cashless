// Function : FUN_4014b430
// Address  : 0x4014b430
// Size     : 50 bytes


void FUN_4014b430(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = 0;
    do {
      FUN_4014a68c(param_1,iVar1);
      iVar2 = iVar1 + 1;
      FUN_4014ab74(param_1,iVar1);
      iVar1 = iVar2;
    } while (iVar2 != 8);
    *(undefined2 *)(param_1 + 0x15c) = 0;
    memw();
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffbf;
  }
  memw();
  return;
}

