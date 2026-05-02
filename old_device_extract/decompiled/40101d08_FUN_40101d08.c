// Function : FUN_40101d08
// Address  : 0x40101d08
// Size     : 204 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40101d08(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_t0;
  char local_51;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  char *pcStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [20];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  local_51 = '\0';
  memw();
  memw();
  iStack_44 = (*(code *)&SUB_4008c01c)(param_3);
  iStack_44 = iStack_44 + 1;
  uVar3 = 0x13;
  uStack_3c = 1;
  uVar2 = 0;
  uStack_50 = param_3;
  uStack_4c = param_4;
  pcStack_48 = &local_51;
  uStack_40 = param_5;
  do {
    if (uVar2 < param_7) {
      if (param_7 - uVar2 <= uVar3) {
        iVar1 = FUN_40102144(param_1,param_2,3,&uStack_50,&iStack_44,auStack_38);
        if (iVar1 == 0) {
          (*(code *)&SUB_4008b3d0)(param_6 + uVar2,auStack_38,param_7 - uVar2);
          goto LAB_40101dc5;
        }
LAB_40101d72:
        param_1 = 0xffffffff;
        uVar3 = in_t0;
        goto LAB_40101d74;
      }
      memw();
      iVar1 = FUN_40102144(param_1,param_2,3,&uStack_50,&iStack_44,param_6 + uVar2);
      if (iVar1 != 0) goto LAB_40101d72;
    }
    else {
LAB_40101dc5:
      FUN_40102884(auStack_38,0x14);
      param_1 = 0;
      uVar3 = in_t0;
LAB_40101d74:
      uVar2 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      in_t0 = uVar3;
    }
    uVar2 = uVar2 + 0x14;
    local_51 = local_51 + '\x01';
    memw();
    memw();
  } while( true );
}

