// Function : FUN_4013167c
// Address  : 0x4013167c
// Size     : 131 bytes


int FUN_4013167c(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != param_2) {
    uVar4 = param_1[1];
    uVar3 = param_2[1];
    if (param_2[1] == 0) {
      if (uVar4 != 0) {
        *param_1 = 1;
        memw();
        (*(code *)&SUB_4008b530)(param_1[2],0,uVar4 << 2);
      }
    }
    else {
      do {
        uVar1 = uVar3;
        uVar3 = uVar1 - 1;
        if (uVar3 == 0) break;
      } while (*(int *)(param_2[2] + uVar3 * 4) == 0);
      *param_1 = *param_2;
      if (uVar4 < uVar1) {
        memw();
        iVar2 = FUN_40131574(param_1,uVar1);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      else {
        (*(code *)&SUB_4008b530)(param_1[2] + uVar1 * 4,0,(uVar4 - uVar1) * 4);
      }
      (*(code *)&SUB_4008b3d0)(param_1[2],param_2[2],uVar1 << 2);
    }
  }
  return 0;
}

