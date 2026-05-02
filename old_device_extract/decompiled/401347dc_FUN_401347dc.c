// Function : FUN_401347dc
// Address  : 0x401347dc
// Size     : 377 bytes


int FUN_401347dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_80;
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [68];
  
  memw();
  iVar1 = FUN_40131ad8(param_4,1);
  if (-1 < iVar1) {
    iVar3 = param_1 + 0x4c;
    iVar1 = FUN_401860ec(param_4,iVar3);
    if (iVar1 < 0) {
      FUN_4013562c(auStack_44);
      FUN_40186008(auStack_68);
      FUN_40186008(auStack_5c);
      FUN_40186008(auStack_50);
      iStack_80 = 0xc;
      while (iStack_80 = iStack_80 + -1, iStack_80 != 0) {
        iVar1 = 0xc;
        do {
          iVar1 = iVar1 + -1;
          if (iVar1 == 0) goto LAB_40134950;
          memw();
          iVar2 = FUN_401368dc(param_1,auStack_68,param_7,param_8);
          if (iVar2 != 0) goto LAB_4013492e;
          memw();
          iVar2 = FUN_4013633c(param_1,auStack_44,auStack_68,param_1 + 0x28,param_9,param_10,0);
          if ((iVar2 != 0) || (iVar2 = FUN_401320e0(param_2,auStack_44,iVar3), iVar2 != 0))
          goto LAB_4013492e;
          iVar2 = FUN_40131ad8(param_2,0);
        } while (iVar2 == 0);
        iVar2 = FUN_40134788(param_1,auStack_5c,param_5,param_6);
        if ((((((iVar2 != 0) ||
               (iVar2 = FUN_401368dc(param_1,auStack_50,param_9,param_10), iVar2 != 0)) ||
              (iVar2 = FUN_4013d5d8(param_3,param_2,param_4), iVar2 != 0)) ||
             ((iVar2 = FUN_40131d18(auStack_5c,auStack_5c,param_3), iVar2 != 0 ||
              (iVar2 = FUN_4013d5d8(auStack_5c,auStack_5c,auStack_50), iVar2 != 0)))) ||
            ((iVar2 = FUN_4013d5d8(auStack_68,auStack_68,auStack_50), iVar2 != 0 ||
             ((iVar2 = FUN_401320e0(auStack_68,auStack_68,iVar3), iVar2 != 0 ||
              (iVar2 = FUN_40132650(param_3,auStack_68,iVar3), iVar2 != 0)))))) ||
           ((iVar2 = FUN_4013d5d8(param_3,param_3,auStack_5c), iVar2 != 0 ||
            (iVar2 = FUN_401320e0(param_3,param_3,iVar3), iVar2 != 0)))) goto LAB_4013492e;
        memw();
        iVar1 = FUN_40131ad8(param_3,0);
        if (iVar1 != 0) goto LAB_4013492e;
      }
LAB_40134950:
      iVar2 = -0x4d00;
LAB_4013492e:
      memw();
      FUN_401356a8(auStack_44);
      FUN_40131548(auStack_68);
      FUN_40131548(auStack_5c);
      FUN_40131548(auStack_50);
      return iVar2;
    }
  }
  return -0x4c80;
}

