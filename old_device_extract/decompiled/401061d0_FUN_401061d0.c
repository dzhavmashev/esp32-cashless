// Function : FUN_401061d0
// Address  : 0x401061d0
// Size     : 364 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401061d0(undefined4 param_1,int param_2,int param_3,undefined1 *param_4,undefined1 *param_5
                 ,int param_6,int param_7,int param_8,uint param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  undefined1 *in_t0;
  undefined1 auStack_c8 [6];
  undefined1 auStack_c2 [6];
  undefined1 auStack_bc [32];
  undefined1 auStack_9c [32];
  undefined1 auStack_7c [88];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = (*(code *)&SUB_4008b33c)(param_4,param_5,6);
  if (-1 < iVar1) goto LAB_401062f4;
  (*(code *)&SUB_4008b3d0)(auStack_c8,param_4,6);
  param_4 = param_5;
  while( true ) {
    (*(code *)&SUB_4008b3d0)(auStack_c2,param_4);
    iVar1 = (*(code *)&SUB_4008b33c)(param_6,param_7,0x20);
    if (iVar1 < 0) {
      (*(code *)&SUB_4008b3d0)(auStack_bc,param_6);
      param_6 = param_7;
      param_4 = in_t0;
    }
    else {
      (*(code *)&SUB_4008b3d0)(auStack_bc,param_7,0x20);
      param_4 = in_t0;
    }
    (*(code *)&SUB_4008b3d0)(auStack_9c,param_6,0x20);
    param_6 = 0x18;
    iVar1 = 0x20;
    if (param_9 != 0x20000) {
      iVar1 = 0x10;
      param_6 = 0x10;
    }
    *(int *)(param_8 + 0x5c) = iVar1;
    *(int *)(param_8 + 0x58) = param_6;
    memw();
    iVar2 = (*(code *)&LAB_40185113_1)(param_10);
    *(int *)(param_8 + 0x60) = iVar2;
    if ((param_9 & 0x18580) == 0) {
      FUN_40101d08(param_1,param_2,param_3,auStack_c8);
    }
    else {
      memw();
      FUN_40101ce8(param_1,param_2,param_3,auStack_c8,0x4c,auStack_7c,iVar1 + param_6 + iVar2);
    }
    (*(code *)&SUB_4008b3d0)(param_8,auStack_7c,*(undefined4 *)(param_8 + 0x58));
    param_5 = auStack_7c;
    (*(code *)&SUB_4008b3d0)
              (param_8 + 0x18,auStack_7c + *(int *)(param_8 + 0x58),*(undefined4 *)(param_8 + 0x5c))
    ;
    (*(code *)&SUB_4008b3d0)
              (param_8 + 0x38,param_5 + *(int *)(param_8 + 0x58) + *(int *)(param_8 + 0x5c),
               *(undefined4 *)(param_8 + 0x60));
    param_3 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
    param_1 = 0;
    in_t0 = param_4;
LAB_401062f4:
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_c8,param_5);
  }
  return;
}

