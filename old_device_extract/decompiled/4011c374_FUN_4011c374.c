// Function : FUN_4011c374
// Address  : 0x4011c374
// Size     : 305 bytes


byte FUN_4011c374(uint *param_1,undefined4 *param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  byte bStack_25;
  int *apiStack_24 [9];
  
  apiStack_24[0] = (int *)0x0;
  if ((param_2 == (undefined4 *)0x0) || (*param_2 = 0, param_1 == (uint *)0x0)) {
    bStack_25 = 0xf0;
    goto LAB_4011c383;
  }
  param_1[7] = param_1[7] + 1;
  if ((param_1[4] == 0) || ((param_1[0xd] & 8) != 0)) {
    memw();
    bStack_25 = FUN_4011c350(param_1);
    param_1[7] = param_1[7] - 1;
    if (bStack_25 != 0) goto LAB_4011c383;
  }
  else {
    if (((param_3 & 4) == 0 && (param_1[0xd] & 3) == 0) && ((char)param_1[3] == '\0')) {
      iVar2 = FUN_4011aedc(param_1 + 4,apiStack_24,param_1[10]);
      if (iVar2 == -1) {
        bStack_25 = 0xfd;
        param_1[7] = param_1[7] - 1;
        memw();
        goto LAB_4011c383;
      }
    }
    else {
      iVar2 = FUN_4011af34(param_1 + 4,apiStack_24);
      if (iVar2 == -1) {
        param_1[7] = param_1[7] - 1;
        memw();
        bStack_25 = FUN_4011c350(param_1);
        if ((bStack_25 != 0) || (bStack_25 = 0xf9, (param_1[0xd] & 1) == 0)) goto LAB_4011c383;
        goto LAB_4011c3b4;
      }
    }
    param_1[7] = param_1[7] - 1;
    if (((param_1[0xd] & 8) == 0) || (iVar2 = FUN_4011cfc4(apiStack_24[0]), iVar2 == 0)) {
      if ((*param_1 & 0xf0) == 0x10) {
        memw();
        iVar2 = FUN_4011cfd8(apiStack_24[0],&bStack_25);
        piVar3 = apiStack_24[0];
        if (iVar2 != 0) {
          if (bStack_25 == 0xf1) {
            bStack_25 = 0;
          }
          goto LAB_4011c383;
        }
      }
      else {
        piVar3 = apiStack_24[0];
        if (apiStack_24[0] == (int *)0x0) {
          piVar3 = (int *)(*(code *)&SUB_40094c54)("ing pcb",0x29e,"_partly","sed > 0");
        }
        piVar3 = (int *)*piVar3;
      }
      uVar1 = *(ushort *)(piVar3 + 2);
      FUN_4011b020();
      param_1[0xc] = param_1[0xc] - (uint)uVar1;
      memw();
      FUN_4011b040();
      if ((code *)param_1[0xf] != (code *)0x0) {
        (*(code *)param_1[0xf])(param_1,1,(uint)uVar1);
      }
      bStack_25 = 0;
      *param_2 = apiStack_24[0];
      memw();
      goto LAB_4011c383;
    }
  }
LAB_4011c3b4:
  bStack_25 = 0xf5;
  memw();
LAB_4011c383:
  memw();
  return bStack_25;
}

