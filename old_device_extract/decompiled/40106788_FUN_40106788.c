// Function : FUN_40106788
// Address  : 0x40106788
// Size     : 88 bytes


int FUN_40106788(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  if (param_2 != 0) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[0x1b] == param_2) {
        memw();
        iVar1 = FUN_40106520(param_1,puVar2 + 5,puVar2[0x15],0,0,0,param_3,param_1[2] + 0x234,
                             param_2,puVar2[0x17]);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x58) = puVar2[0x16];
          *(undefined4 *)(iVar1 + 0x70) = 1;
          memw();
          return iVar1;
        }
        return 0;
      }
    }
  }
  return 0;
}

