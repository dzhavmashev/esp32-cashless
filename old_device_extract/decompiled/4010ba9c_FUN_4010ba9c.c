// Function : FUN_4010ba9c
// Address  : 0x4010ba9c
// Size     : 81 bytes


undefined4 FUN_4010ba9c(int param_1,uint param_2)

{
  undefined4 uVar1;
  int in_t0;
  
  if (param_1 == 0) {
    param_1 = in_t0;
    (*(code *)&SUB_40094c54)("if_init",0x24f,"uf_free","ealloc: p != NULL");
  }
  uVar1 = 1;
  if ((param_2 < 0x10000) && (uVar1 = 0, param_2 != 0)) {
    uVar1 = 1;
    if ((param_2 & 0xffff) <= (uint)*(ushort *)(param_1 + 10)) {
      *(short *)(param_1 + 8) = *(short *)(param_1 + 8) - (short)param_2;
      uVar1 = 0;
      *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
      *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) - (short)param_2;
      memw();
    }
  }
  memw();
  return uVar1;
}

