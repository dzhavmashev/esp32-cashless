// Function : FUN_40107300
// Address  : 0x40107300
// Size     : 55 bytes


undefined4 * FUN_40107300(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0xc);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"wifi_ap","i_netif",uVar2,"wifi_ap");
  }
  else {
    puVar1[2] = param_1;
    *puVar1 = 0x4010729c;
    memw();
  }
  return puVar1;
}

