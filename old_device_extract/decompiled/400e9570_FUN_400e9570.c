// Function : FUN_400e9570
// Address  : 0x400e9570
// Size     : 251 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400e9570(undefined4 param_1,uint param_2,char param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 local_b0 [32];
  undefined1 uStack_90;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined1 auStack_4b [6];
  undefined1 uStack_45;
  undefined2 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uStack_45 = 0;
  uStack_44 = 0;
  uStack_4c = 0;
  uStack_50 = 1;
  uStack_40 = 0;
  uStack_3c = 0x81;
  func_0x4008b538(auStack_4b,0,6);
  local_b0[0] = 0;
  uStack_90 = 0;
  uStack_38 = 0;
  uStack_34 = 1;
  uVar1 = FUN_400e81d0();
  param_2 = param_2 & 0xff;
  uVar2 = 0;
  if ((uVar1 & 1) != 0) {
    if ((param_3 != '\0') && (iVar3 = FUN_40146e58(0,local_b0), iVar3 != 0)) {
      uVar5 = func_0x40085c04();
      uVar2 = FUN_401847ec("face_ip");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
      FUN_4012105c(" 0x%x\r\n",uVar4,uVar2,0x161,"localIP");
    }
    iVar3 = FUN_40146a64();
    uVar4 = 0;
    if (iVar3 == 0) goto LAB_400e9655;
    uVar5 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    FUN_4012105c("iled!\r\n",uVar4,uVar2,0x165,"localIP");
    uVar2 = 0;
  }
  while( true ) {
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) break;
    uVar4 = func_0x40082ecc();
LAB_400e9655:
    uVar2 = 1;
    if (param_2 != 0) {
      uVar2 = FUN_400e8448(&DAT_3ffc516c,uVar4);
    }
  }
  return uVar2;
}

