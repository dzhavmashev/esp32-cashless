// Function : FUN_401342c4
// Address  : 0x401342c4
// Size     : 477 bytes


int FUN_401342c4(uint *param_1,undefined4 param_2,uint param_3,undefined4 *param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  if (param_3 < *param_1) {
    return -0x3080;
  }
  puVar3 = param_1 + 0xd;
  puVar4 = param_1 + 1;
  memw();
  iVar1 = FUN_40133fd4(puVar3,puVar4);
  if (iVar1 != 0) {
    return iVar1;
  }
  FUN_40186008(auStack_38);
  if (param_5 == 0) {
    iVar1 = FUN_4013167c(auStack_38,puVar3);
  }
  else {
    FUN_40186008(auStack_2c);
    puVar6 = param_1 + 7;
    iVar1 = FUN_401860ec(puVar6,param_1 + 0x1c);
    if (iVar1 == 0) {
      puVar5 = param_1 + 0x16;
      iVar1 = FUN_40131ad8(puVar5,1);
      if (iVar1 == 0) {
        iVar1 = FUN_4013400c(puVar5,puVar4,param_5,param_6);
        if ((iVar1 == 0) && (iVar1 = FUN_4013400c(auStack_2c,puVar4,param_5,param_6), iVar1 == 0)) {
          puVar7 = param_1 + 0x19;
          iVar1 = FUN_4013d5d8(puVar7,puVar5,auStack_2c);
          if ((iVar1 == 0) &&
             ((((iVar1 = FUN_401320e0(puVar7,puVar7,puVar4), iVar1 == 0 &&
                (iVar1 = FUN_40132650(puVar7,puVar7,puVar4), iVar1 == 0)) &&
               (iVar1 = FUN_4013d5d8(puVar7,puVar7,auStack_2c), iVar1 == 0)) &&
              (iVar1 = FUN_401320e0(puVar7,puVar7,puVar4), iVar1 == 0)))) {
            iVar1 = FUN_4013d3d8(puVar7,puVar7,puVar6,puVar4,param_1 + 0x13);
          }
        }
      }
      else {
        iVar1 = FUN_4013d5d8(puVar5,puVar5,puVar5);
        if ((iVar1 == 0) && (iVar1 = FUN_401320e0(puVar5,puVar5,puVar4), iVar1 == 0)) {
          puVar6 = param_1 + 0x19;
          iVar1 = FUN_4013d5d8(puVar6,puVar6,puVar6);
          if (iVar1 == 0) {
            iVar1 = FUN_401320e0(puVar6,puVar6,puVar4);
            goto LAB_4013432d;
          }
        }
      }
LAB_4013444c:
      memw();
      FUN_40131548(auStack_2c);
      if (iVar1 != 0) goto LAB_4013445c;
    }
    else {
      iVar1 = FUN_4013167c(param_1 + 0x1c,puVar6);
      if ((iVar1 != 0) || (iVar1 = FUN_40131700(param_1 + 0x16,1), iVar1 != 0)) goto LAB_4013444c;
      iVar1 = FUN_40131700(param_1 + 0x19,1);
LAB_4013432d:
      if (iVar1 != 0) goto LAB_4013444c;
    }
    iVar1 = FUN_4013d5d8(auStack_38,puVar3,param_1 + 0x16);
    if (iVar1 != 0) goto LAB_4013445c;
    iVar1 = FUN_401320e0(auStack_38,auStack_38,puVar4);
  }
  if (iVar1 == 0) {
    puVar3 = param_1 + 0x10;
    iVar1 = FUN_4013d3d8(puVar3,auStack_38,param_1 + 7,puVar4,param_1 + 0x13);
    if ((iVar1 == 0) &&
       ((param_5 == 0 ||
        ((iVar1 = FUN_4013d5d8(puVar3,puVar3,param_1 + 0x19), iVar1 == 0 &&
         (iVar1 = FUN_401320e0(puVar3,puVar3,puVar4), iVar1 == 0)))))) {
      uVar2 = FUN_401317d8(puVar3);
      *param_4 = uVar2;
      memw();
      iVar1 = FUN_40131900(puVar3,param_2,uVar2);
    }
  }
LAB_4013445c:
  memw();
  FUN_40131548(auStack_38);
  if (iVar1 != 0) {
    iVar1 = iVar1 + -0x3300;
  }
  return iVar1;
}

