// Function : FUN_40107ac4
// Address  : 0x40107ac4
// Size     : 303 bytes


int FUN_40107ac4(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int aiStack_24 [9];
  
  if ((int)param_3 < 0) {
    param_3 = 0x7fffffff;
  }
  if (param_1 != (undefined4 *)0x0) goto LAB_40107aec;
  pcVar7 = "ed != 0";
  uVar5 = 0x3da;
LAB_40107ae0:
  while( true ) {
    memw();
    (*(code *)&SUB_40094c54)("!= NULL",uVar5,"ke_addr",pcVar7);
LAB_40107aec:
    if ((*(uint *)*param_1 & 0xf0) == 0x10) break;
    pcVar7 = "t given";
    uVar5 = 0x3db;
  }
  uVar5 = 0xc;
  if ((param_4 & 8) == 0) {
    uVar5 = 8;
  }
  iVar2 = 0;
LAB_40107b14:
  iVar6 = param_1[1];
  if (param_1[1] == 0) {
    cVar1 = FUN_4011c57c(*param_1,aiStack_24,uVar5);
    if (cVar1 != '\0') {
      if (iVar2 == 0) {
        iVar2 = FUN_4011d9e4((int)cVar1);
        if (iVar2 != 0) {
          piVar3 = (int *)FUN_40173a8c();
          *piVar3 = iVar2;
        }
        memw();
        return -(uint)(cVar1 != -0xf);
      }
      if ((param_4 & 1) != 0) {
        return iVar2;
      }
      goto LAB_40107bd8;
    }
    if (aiStack_24[0] != 0) {
      param_1[1] = aiStack_24[0];
      memw();
      iVar6 = aiStack_24[0];
      goto LAB_40107b1a;
    }
    pcVar7 = "ealloc: p != NULL";
    uVar5 = 0x401;
  }
  else {
LAB_40107b1a:
    aiStack_24[0] = iVar6;
    uVar4 = (uint)*(ushort *)(aiStack_24[0] + 8);
    if ((int)param_3 <= (int)uVar4) {
      uVar4 = param_3 & 0xffff;
    }
    iVar6 = param_2 + iVar2;
    iVar2 = uVar4 + iVar2;
    memw();
    FUN_4010bfb8(aiStack_24[0],iVar6,uVar4,0);
    if ((int)param_3 < (int)uVar4) {
      pcVar7 = "ernally";
      uVar5 = 0x419;
    }
    else {
      if ((param_4 & 1) != 0) {
        if (iVar2 != 0) {
          return iVar2;
        }
        goto LAB_40107bf5;
      }
      if (uVar4 <= *(ushort *)(aiStack_24[0] + 8)) goto LAB_40107bbc;
      pcVar7 = "derflow";
      uVar5 = 0x41f;
    }
  }
  goto LAB_40107ae0;
LAB_40107bbc:
  if ((int)(*(ushort *)(aiStack_24[0] + 8) - uVar4) < 1) {
    param_1[1] = 0;
    memw();
    FUN_4010bb10();
  }
  else {
    uVar5 = FUN_4010bdcc(aiStack_24[0],uVar4);
    param_1[1] = uVar5;
  }
  param_3 = param_3 - uVar4;
  uVar5 = 0x1c;
  if (param_3 == 0) {
    if (iVar2 == 0) {
LAB_40107bf5:
      iVar2 = 0;
    }
    else {
LAB_40107bd8:
      memw();
      FUN_4011c218(*param_1,iVar2);
    }
    return iVar2;
  }
  goto LAB_40107b14;
}

