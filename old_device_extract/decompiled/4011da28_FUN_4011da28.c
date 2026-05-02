// Function : FUN_4011da28
// Address  : 0x4011da28
// Size     : 73 bytes


undefined4 FUN_4011da28(int *param_1,ushort param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_4010bb10();
    }
    iVar1 = FUN_4010bbc4(0x4a,param_2,0x280);
    *param_1 = iVar1;
    if (iVar1 != 0) {
      if (*(ushort *)(iVar1 + 10) < param_2) {
        memw();
        iVar1 = (*(code *)&SUB_40094c54)("ld size",0x73,"etbuf.c",&DAT_3f412d5c);
      }
      param_1[1] = iVar1;
      memw();
      return *(undefined4 *)(iVar1 + 4);
    }
  }
  return 0;
}

