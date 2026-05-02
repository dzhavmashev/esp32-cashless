// Function : FUN_40124c68
// Address  : 0x40124c68
// Size     : 194 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40124c68(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
  memw();
  param_1[4] = 7;
  iVar1 = param_1[0xb];
  param_1[0x62] = 0;
  param_1[0xd] = 0;
  param_1[0xb] = iVar1 + 1;
  if (iVar1 + 1 < 5) {
    uVar2 = 0;
    puVar3 = (undefined1 *)0x0;
    if (param_1[0x6d] == 2) {
      uVar2 = 0;
      if ((param_1[0x6f] & 0x3c0a1U) != 0) {
        uStack_3a = 0xdd;
        uStack_39 = 0x14;
        uStack_37 = 0xf;
        uStack_36 = 0xac;
        uStack_35 = 4;
        memw();
        uStack_38 = 0;
        memw();
        memw();
        FUN_40106150(param_1 + 0x23,0x20,*param_1 + 0x5c,param_1 + 2,auStack_34,
                     (param_1[0x6f] & 0x18580U) != 0);
        uVar2 = 0x16;
        puVar3 = &uStack_3a;
      }
    }
    memw();
    FUN_40124bb4(*param_1,param_1,0x88,0,param_1 + 0x13,puVar3,uVar2,0,0);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return;
}

