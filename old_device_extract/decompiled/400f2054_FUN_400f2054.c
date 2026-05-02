// Function : FUN_400f2054
// Address  : 0x400f2054
// Size     : 92 bytes


byte FUN_400f2054(int *param_1)

{
  byte bVar1;
  int iVar2;
  byte abStack_21 [33];
  
  abStack_21[0] = 0;
  if (param_1 != (int *)0x0) {
    abStack_21[0] = 0;
    if (*param_1 != 0) {
      do {
        iVar2 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar2 != 1);
    }
    if (*(char *)((int)param_1 + 5) == '\0') {
      iVar2 = FUN_400f7574((char)param_1[1],abStack_21,1,0x14);
      bVar1 = 0;
      if (0 < iVar2) {
        *(undefined1 *)((int)param_1 + 5) = 1;
        *(byte *)((int)param_1 + 6) = abStack_21[0];
        bVar1 = abStack_21[0];
      }
    }
    else {
      bVar1 = *(byte *)((int)param_1 + 6);
    }
    abStack_21[0] = bVar1;
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0);
    }
  }
  return abStack_21[0];
}

