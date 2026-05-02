// Function : FUN_40133518
// Address  : 0x40133518
// Size     : 319 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40133518(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                undefined4 param_5,uint param_6,uint param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_70 [12];
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_401864d0(*param_1);
  iVar4 = 0x40;
  if (iVar1 == 7) {
    iVar4 = 0x80;
  }
  iVar3 = param_1[2];
  uVar2 = FUN_401864c4(*param_1);
  FUN_40138f64(auStack_70);
  iVar1 = FUN_4013905c(auStack_70,*param_1,0);
  if (((iVar1 == 0) && (iVar1 = FUN_40139174(param_1,param_2,param_3), iVar1 == 0)) &&
     (iVar1 = FUN_40139174(param_1,param_4,param_6), iVar1 == 0)) {
    (*(code *)&SUB_4008b530)(param_8,0x21,uVar2);
    for (; param_6 <= param_7; param_6 = param_6 + 1) {
      iVar1 = FUN_40138fe0(auStack_70,param_1);
      if (((iVar1 != 0) || (iVar1 = FUN_401391c4(auStack_70,auStack_64), iVar1 != 0)) ||
         ((FUN_401334b0(param_8,auStack_64,uVar2,param_6,param_5), param_6 < param_7 &&
          (iVar1 = FUN_40139174(param_1,param_4 + param_6,1), iVar1 != 0)))) goto LAB_40133631;
    }
    iVar1 = FUN_401391c4(param_1,auStack_64);
    if (((iVar1 == 0) && (iVar1 = FUN_40139114(param_1), iVar1 == 0)) &&
       ((iVar1 = FUN_40139174(param_1,iVar3 + iVar4,iVar4), iVar1 == 0 &&
        ((iVar1 = FUN_40139174(param_1,param_8,uVar2), iVar1 == 0 &&
         (iVar1 = FUN_401391c4(param_1,param_8), iVar1 == 0)))))) {
      iVar1 = FUN_401393f0(param_1);
    }
  }
LAB_40133631:
  memw();
  FUN_40138f78(auStack_70);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

