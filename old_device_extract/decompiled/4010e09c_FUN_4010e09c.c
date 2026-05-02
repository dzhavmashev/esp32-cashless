// Function : FUN_4010e09c
// Address  : 0x4010e09c
// Size     : 227 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010e09c(int *param_1,int *param_2)

{
  ushort uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 == (int *)0x0) {
    (*(code *)&SUB_40094c54)("id cseg",0x424,"d_close",&DAT_3f4109b0);
  }
  uVar2 = FUN_40185288(*(undefined2 *)(param_1[3] + 0xc));
  if ((uVar2 & 1) == 0) {
    do {
      iVar4 = *(int *)(param_2[3] + 4);
      if ((int)(((uint)*(ushort *)(param_1 + 2) + _DAT_3ffc6348) -
               ((uint)*(ushort *)(param_2 + 2) + iVar4)) < 0) {
        if (0 < (int)(((uint)*(ushort *)(param_1 + 2) + _DAT_3ffc6348) - iVar4)) {
          *(short *)(param_1 + 2) = (short)iVar4 - (short)_DAT_3ffc6348;
          memw();
          memw();
          FUN_4010bd2c(param_1[1]);
        }
        break;
      }
      uVar2 = FUN_40185288(*(undefined2 *)(param_2[3] + 0xc));
      if ((uVar2 & 1) != 0) {
        uVar1 = *(ushort *)(param_1[3] + 0xc);
        uVar2 = FUN_40185288(1);
        iVar4 = param_1[3];
        uVar2 = (uint)uVar1 | uVar2 & 0xffff;
        *(char *)(iVar4 + 0xc) = (char)uVar2;
        *(char *)(iVar4 + 0xd) = (char)(uVar2 >> 8);
        memw();
      }
      piVar3 = (int *)*param_2;
      memw();
      FUN_4010ce44(param_2);
      param_2 = piVar3;
    } while (piVar3 != (int *)0x0);
  }
  else {
    FUN_4010ce5c(param_2);
    param_2 = (int *)0x0;
  }
  *param_1 = (int)param_2;
  memw();
  return;
}

