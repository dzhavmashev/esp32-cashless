// Function : FUN_401260fc
// Address  : 0x401260fc
// Size     : 152 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401260fc(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_t0;
  undefined1 auStack_424 [512];
  undefined1 auStack_224 [512];
  int local_24;
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40128a90(param_4,auStack_424,0x200,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44));
  if (-1 < iVar1) goto LAB_40126154;
  do {
    param_1 = -1;
    param_6 = in_t0;
    while( true ) {
      param_3 = local_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (local_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      in_t0 = param_6;
LAB_40126154:
      iVar1 = FUN_40128a90(param_6,auStack_224,0x200,
                           *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44));
      if (iVar1 < 0) break;
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44);
      memw();
      param_1 = FUN_40126034(param_1 + 0x48,param_2,param_3,auStack_424,uVar2,param_5,auStack_224,
                             uVar2,param_7);
      param_1 = param_1 >> 0x1f;
      param_6 = in_t0;
    }
  } while( true );
}

