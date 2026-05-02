// Function : FUN_400e145c
// Address  : 0x400e145c
// Size     : 184 bytes


uint FUN_400e145c(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (param_1 != (uint *)0x0) {
    if ((param_1[2] & 0x7f) == 0) {
      (*(code *)&LAB_40184133_1)(param_1);
    }
    uVar2 = (byte)param_1[2] & 0x20;
    if ((((byte)param_1[2] & 0x20) != 0) && (uVar2 = 0, param_2 != 0)) {
      for (uVar2 = *param_1; uVar2 != 0; uVar2 = (*(code *)&LAB_40183a9a_2)(uVar2)) {
        iVar3 = *(int *)(uVar2 + 0xc);
        iVar1 = 0;
        if (iVar3 != 0) {
          iVar1 = func_0x4008c024(iVar3);
        }
        if (iVar1 == param_3) {
          iVar1 = 0;
          while( true ) {
            if (iVar1 == param_3) {
              return uVar2;
            }
            if (*(char *)(param_2 + iVar1) != *(char *)(iVar3 + iVar1)) break;
            iVar1 = iVar1 + 1;
          }
        }
      }
      uVar2 = FUN_40183ab0(param_1,param_4);
      if (uVar2 != 0) {
        iVar1 = FUN_400da91c(param_4,param_2,param_3);
        if (iVar1 == 0) {
          FUN_400e04ac(param_1,uVar2);
          uVar2 = 0;
        }
        else {
          *(byte *)(uVar2 + 8) = *(byte *)(uVar2 + 8) | 0x80;
          *(int *)(uVar2 + 0xc) = iVar1;
        }
      }
    }
  }
  return uVar2;
}

