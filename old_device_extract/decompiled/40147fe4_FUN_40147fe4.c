// Function : FUN_40147fe4
// Address  : 0x40147fe4
// Size     : 168 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40147fe4(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined1 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  auStack_54[0] = 0x4e;
  auStack_54[1] = 0x45;
  auStack_54[2] = 0x57;
  auStack_54[3] = 0x49;
  memw();
  uStack_30 = param_5;
  uStack_2c = param_6;
  uStack_50 = 0x5644;
  memw();
  if (((_DAT_3ffc1a34 != 0) && (*(int *)(_DAT_3ffc1a34 + 0x154) != 0)) && (param_3 <= _DAT_3ffca410)
     ) {
    pcVar3 = *(code **)(_DAT_3ffc1a34 + 0x150);
    uVar1 = auStack_54[param_3];
    memw();
    uVar2 = (**(code **)(_DAT_3ffc1a34 + 0x158))();
    memw();
    (*pcVar3)(param_3,"g state","rypto.c",uVar1,uVar2,"g state",&DAT_3f42161d);
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x154))(param_3,"g state",param_4);
    (**(code **)(_DAT_3ffc1a34 + 0x150))(param_3,"g state","o %s",&DAT_3f421885);
  }
  return;
}

