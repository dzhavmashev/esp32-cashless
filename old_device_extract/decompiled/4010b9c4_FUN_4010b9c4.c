// Function : FUN_4010b9c4
// Address  : 0x4010b9c4
// Size     : 106 bytes


undefined4 FUN_4010b9c4(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int in_t0;
  
  if (param_1 == 0) {
    param_1 = in_t0;
    (*(code *)&SUB_40094c54)("if_init",0x1e3,"_header","ealloc: p != NULL");
  }
  uVar1 = 1;
  if ((param_2 < 0x10000) && (uVar1 = 0, param_2 != 0)) {
    uVar3 = (param_2 & 0xffff) + (uint)*(ushort *)(param_1 + 8);
    uVar1 = 1;
    if ((param_2 & 0xffff) <= (uVar3 & 0xffff)) {
      if ((*(byte *)(param_1 + 0xc) & 0x80) == 0) {
        if (param_3 == 0) {
          return 1;
        }
        uVar2 = *(int *)(param_1 + 4) - param_2;
      }
      else {
        uVar2 = *(int *)(param_1 + 4) - param_2;
        if (uVar2 < param_1 + 0x18U) {
          return 1;
        }
      }
      uVar1 = 0;
      *(uint *)(param_1 + 4) = uVar2;
      *(short *)(param_1 + 10) = (short)param_2 + *(short *)(param_1 + 10);
      *(short *)(param_1 + 8) = (short)uVar3;
      memw();
      memw();
    }
  }
  return uVar1;
}

