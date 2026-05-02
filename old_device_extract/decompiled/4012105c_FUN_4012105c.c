// Function : FUN_4012105c
// Address  : 0x4012105c
// Size     : 200 bytes


/* WARNING: Removing unreachable block (ram,0x4012108e) */

void FUN_4012105c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint unaff_retaddr;
  uint uVar1;
  undefined4 uVar2;
  undefined1 *local_80;
  undefined1 *puStack_7c;
  undefined4 uStack_78;
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
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
  uStack_3c = 4;
  memw();
  uStack_6c = param_2;
  uStack_68 = param_3;
  uStack_64 = param_4;
  uStack_60 = param_5;
  uStack_5c = param_6;
  uVar1 = (*(code *)&SUB_4008c01c)(param_1);
  if (7 < uVar1) {
    if (*(char *)(param_1 + 6) == 'E') {
      uVar2 = 1;
    }
    else {
      if (*(char *)(param_1 + 6) != 'W') goto LAB_401210e0;
      uVar2 = 2;
      memw();
    }
    uStack_78 = uStack_3c;
    puStack_7c = puStack_40;
    local_80 = puStack_44;
    memw();
    puStack_38 = local_80;
    puStack_34 = puStack_7c;
    uStack_30 = uStack_78;
    puStack_2c = local_80;
    puStack_28 = puStack_7c;
    uStack_24 = uStack_78;
    FUN_401209ec(uVar2,(unaff_retaddr & 0x3fffffff | 0x40000000) - 3,"V_EVENT",param_1);
  }
LAB_401210e0:
  FUN_400f2210(param_1,puStack_44,puStack_40,uStack_3c);
  return;
}

