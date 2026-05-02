// Function : FUN_401604d4
// Address  : 0x401604d4
// Size     : 152 bytes


void FUN_401604d4(int *param_1,char param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = *param_1;
  if ((**(uint **)(iVar1 + 0x2c) & 0x20000) == 0) {
    if ((param_2 == '\0') && (*(char *)((int)param_1 + 0xd) == '\0')) {
      if (*(char *)((int)param_1 + 0xf) != '\0') {
        *(undefined1 *)((int)param_1 + 0xf) = 0;
        *(undefined1 *)((int)param_1 + 0xd) = 0;
        memw();
      }
      memw();
      FUN_401647d0(*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x2c));
      if ((**(uint **)(*param_1 + 0x2c) & 0x40) != 0) {
        FUN_40188920();
        puVar2 = *(uint **)(*param_1 + 0x2c);
        iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4);
        if ((*puVar2 & 0x40000) != 0) {
          iVar1 = iVar1 + 4;
        }
        *(undefined2 *)(iVar1 + 2) = *(undefined2 *)((int)puVar2 + 10);
        memw();
      }
      memw();
      FUN_40187dd4(*param_1,(char)param_1[1]);
      return;
    }
  }
  else {
    *param_1 = 0;
    *(undefined1 *)((int)param_1 + 0x12) = 0;
    memw();
    memw();
    FUN_40147fe4(6,0x40,3,0x3f4357ff);
    if ((**(uint **)(iVar1 + 0x2c) & 0x400000) == 0) {
      FUN_401604bc(param_1,iVar1,1);
      return;
    }
    FUN_40163c48(iVar1,1);
  }
  return;
}

