// Function : FUN_40123420
// Address  : 0x40123420
// Size     : 338 bytes


int FUN_40123420(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uStack_38;
  uint uStack_34;
  int iStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  iVar1 = FUN_400f9524("_update",0,&uStack_38);
  uVar2 = uStack_38;
  if (iVar1 == 0x1101) {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"ate","hy_init",uVar2,"ate","_handle");
    return 0x1101;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_400f994c(uStack_38,"Fi/BT.\n",&uStack_34);
  if (iVar1 != 0) goto LAB_40123562;
  uVar3 = FUN_4016b0ac();
  if ((uVar3 & 0xfffeffff) == uStack_34) {
    iStack_30 = 6;
    memw();
    iVar1 = FUN_400f9a2c(uVar2,"version",&uStack_2c,&iStack_30);
    if (iVar1 != 0) goto LAB_40123562;
    if (iStack_30 == 6) {
      iVar1 = FUN_4011ecfc(&uStack_26);
      if (iVar1 != 0) {
        (*(code *)&SUB_4008effc)(iVar1,"ta_mac)",0x261,"_handle","cal_mac");
      }
      iVar1 = (*(code *)&SUB_4008b33c)(&uStack_26,&uStack_2c,6);
      if (iVar1 != 0) {
        uVar2 = (*(code *)&SUB_40094b80)();
        memw();
        FUN_4012113c(1,"ate","_init.c",uVar2,"ate","_handle",uStack_26,uStack_25,uStack_24,uStack_23
                     ,uStack_22,uStack_21,uStack_2c,uStack_2b,uStack_2a,uStack_29,uStack_28,
                     uStack_27);
        goto LAB_40123521;
      }
      iStack_30 = 0x770;
      memw();
      iVar1 = FUN_400f9a2c(uVar2,"x:%02x\n",param_1,&iStack_30);
      if (iVar1 != 0) {
        uVar2 = (*(code *)&SUB_40094b80)();
        memw();
        FUN_4012113c(1,"ate","al_data",uVar2,"ate","_handle",iVar1);
        goto LAB_40123562;
      }
      if (iStack_30 == 0x770) goto LAB_40123562;
    }
    iVar1 = 0x104;
  }
  else {
LAB_40123521:
    iVar1 = -1;
  }
LAB_40123562:
  FUN_400f9a40(uStack_38);
  return iVar1;
}

