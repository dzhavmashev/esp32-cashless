// Function : FUN_40135e8c
// Address  : 0x40135e8c
// Size     : 216 bytes


int FUN_40135e8c(int param_1,int param_2,int param_3,uint *param_4,char *param_5,uint param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  memw();
  uVar2 = FUN_401317d8(param_1 + 4);
  iVar3 = FUN_401863d8(param_1);
  iVar5 = -0x4e80;
  if (iVar3 == 2) {
    *param_4 = uVar2;
    if (uVar2 <= param_6) {
      iVar5 = FUN_40131880(param_2,param_5,uVar2);
      if (iVar5 != 0) goto LAB_40135eb0;
      goto LAB_40135ec9;
    }
  }
  else {
LAB_40135ec9:
    memw();
    iVar3 = FUN_401863d8(param_1);
    if (iVar3 != 1) goto LAB_40135eb0;
    iVar3 = FUN_40131ad8(param_2 + 0x18,0);
    if (iVar3 == 0) {
      if (param_6 != 0) {
        *param_5 = '\0';
        memw();
        *param_4 = 1;
        iVar5 = 0;
LAB_40135ef3:
        memw();
        goto LAB_40135eb0;
      }
    }
    else if (param_3 == 0) {
      uVar4 = uVar2 * 2 + 1;
      *param_4 = uVar4;
      if (uVar4 <= param_6) {
        *param_5 = '\x04';
        memw();
        memw();
        iVar5 = FUN_40131900(param_2,param_5 + 1,uVar2);
        if (iVar5 != 0) goto LAB_40135eb0;
        param_5 = param_5 + uVar2 + 1;
        param_2 = param_2 + 0xc;
LAB_40135f2d:
        iVar5 = FUN_40131900(param_2,param_5,uVar2);
        goto LAB_40135ef3;
      }
    }
    else {
      if (param_3 != 1) goto LAB_40135eb0;
      *param_4 = uVar2 + 1;
      if (uVar2 + 1 <= param_6) {
        memw();
        cVar1 = FUN_4018601c(param_2 + 0xc,0);
        *param_5 = cVar1 + '\x02';
        memw();
        param_5 = param_5 + 1;
        memw();
        goto LAB_40135f2d;
      }
    }
  }
  iVar5 = -0x4f00;
LAB_40135eb0:
  memw();
  return iVar5;
}

