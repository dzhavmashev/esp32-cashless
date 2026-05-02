// Function : FUN_40170e00
// Address  : 0x40170e00
// Size     : 95 bytes


undefined4 FUN_40170e00(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *local_40 [16];
  
  iVar2 = 1;
  do {
    iVar1 = FUN_40170bfc(param_2,local_40);
    uVar3 = 0;
    if (*(int *)(param_2 + 0x14) == param_1[4]) {
      uVar3 = 4;
    }
    if (iVar1 != 0) {
      return 2;
    }
    if (local_40[0] != (code *)0x0) {
      iVar1 = (*local_40[0])(1,uVar3 | 2,*param_1,param_1[1],param_1,param_2);
      if (iVar1 == 7) {
        *param_3 = iVar2;
        return 7;
      }
      if (iVar1 != 8) {
        return 2;
      }
    }
    if (uVar3 != 0) {
      (*(code *)&SUB_40094bc8)();
    }
    FUN_40170ddc(param_2,local_40);
    iVar2 = iVar2 + 1;
  } while( true );
}

