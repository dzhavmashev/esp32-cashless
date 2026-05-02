// Function : FUN_400f1f64
// Address  : 0x400f1f64
// Size     : 102 bytes


int FUN_400f1f64(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iStack_28;
  uint uStack_24;
  
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      do {
        iVar2 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar2 != 1);
    }
    cVar1 = (char)param_1[1];
    puVar3 = &DAT_3ff40000;
    if ((cVar1 != '\0') && (puVar3 = &DAT_3ff50000, cVar1 != '\x01')) {
      puVar3 = &DAT_3ff6e000;
    }
    memw();
    uStack_24 = *(uint *)(puVar3 + 0x1c);
    memw();
    memw();
    iVar2 = 0x80 - (uStack_24 >> 0x10 & 0xff);
    iStack_28 = 0;
    iVar4 = FUN_400f7738(cVar1,&iStack_28);
    if ((iVar4 == 0) && (iStack_28 != 0)) {
      iVar2 = iStack_28;
    }
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0);
    }
  }
  return iVar2;
}

