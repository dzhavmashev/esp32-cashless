// Function : FUN_400f80b4
// Address  : 0x400f80b4
// Size     : 85 bytes


int FUN_400f80b4(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != 0) goto LAB_400f80dc;
  iVar2 = FUN_400f7f5c();
  while( true ) {
    bVar1 = false;
    iVar5 = 0x10;
    iVar3 = 0;
    if (iVar2 != 0) break;
    (*(code *)&SUB_40094c54)("_update/esp_ota_ops.c",0x247,"actory\n"," to it\"");
    param_1 = 0;
LAB_400f80dc:
    iVar2 = FUN_400f8ed8(param_1);
  }
  do {
    iVar4 = FUN_400f8eb4(0,iVar5,0);
    if (iVar4 != 0) {
      if (iVar3 == 0) {
        iVar3 = iVar4;
      }
      if (iVar2 == iVar4) {
        bVar1 = true;
      }
      else if (bVar1) {
        return iVar4;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x20);
  return iVar3;
}

