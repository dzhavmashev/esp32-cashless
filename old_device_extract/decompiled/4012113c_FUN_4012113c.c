// Function : FUN_4012113c
// Address  : 0x4012113c
// Size     : 156 bytes


/* WARNING: Removing unreachable block (ram,0x4012117d) */

void FUN_4012113c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint unaff_retaddr;
  int iVar1;
  undefined1 auStack_70 [12];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [32];
  
  puStack_40 = auStack_70;
  puStack_44 = auStack_20;
  uStack_3c = 0xc;
  memw();
  uStack_64 = param_4;
  uStack_60 = param_5;
  uStack_5c = param_6;
  iVar1 = (*(code *)&SUB_4008bdec)(param_2,"g state");
  if (iVar1 != 0) {
    puStack_38 = puStack_44;
    puStack_34 = puStack_40;
    uStack_30 = uStack_3c;
    if ((param_1 == 1) || (param_1 == 2)) {
      puStack_2c = puStack_44;
      puStack_28 = puStack_40;
      uStack_24 = uStack_3c;
      memw();
      FUN_401209ec(param_1,(unaff_retaddr & 0x3fffffff | 0x40000000) - 3,param_2,param_3);
    }
  }
  FUN_40121124(param_1,param_2,param_3,puStack_44,puStack_40,uStack_3c);
  return;
}

