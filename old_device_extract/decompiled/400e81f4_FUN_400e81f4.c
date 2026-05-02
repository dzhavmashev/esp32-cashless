// Function : FUN_400e81f4
// Address  : 0x400e81f4
// Size     : 582 bytes


byte FUN_400e81f4(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  uVar2 = FUN_400e81d0();
  if (uVar2 == param_1) {
LAB_400e81ff:
    bVar1 = 1;
  }
  else {
    if (uVar2 == 0 && param_1 != 0) {
      iVar3 = FUN_400e7fec(DAT_3ffbdb88);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else if ((uVar2 != 0) && (param_1 == 0)) {
      if (DAT_3ffc517c != 0) {
        DAT_3ffc517c = uVar2 == 0 && param_1 != 0;
        iVar3 = FUN_401468ac();
        if (iVar3 != 0) {
          uVar8 = func_0x40085c04();
          uVar4 = FUN_401847ec("02X%02X");
          uVar5 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
          FUN_4012105c("it %d\r\n",uVar5,uVar4,0x2e0,"FiStart",iVar3);
          DAT_3ffc517c = 1;
          return 0;
        }
        if (DAT_3ffc517e != 0) {
          iVar3 = FUN_40106dc0();
          DAT_3ffc517e = iVar3 != 0;
        }
        return DAT_3ffc517e ^ 1;
      }
      goto LAB_400e81ff;
    }
    if ((param_1 & 1) == 0) {
LAB_400e8312:
      iVar3 = FUN_401467e4(param_1);
      if (iVar3 == 0) {
        if (DAT_3ffc516d == '\0') {
LAB_400e83ec:
          bVar1 = DAT_3ffc517c;
          if (DAT_3ffc517c == 0) {
            DAT_3ffc517c = 1;
            iVar3 = FUN_40146850();
            if (iVar3 == 0) {
              return DAT_3ffc517c;
            }
            DAT_3ffc517c = bVar1;
            uVar8 = func_0x40085c04();
            uVar4 = FUN_401847ec("02X%02X");
            uVar5 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
            FUN_4012105c("P! %d\r\n",uVar5,uVar4,0x2d2,"tByName",iVar3);
            return DAT_3ffc517c;
          }
          goto LAB_400e81ff;
        }
        if (((param_1 & 1) == 0) || (iVar3 = FUN_40146f9c(0,8), iVar3 == 0)) {
          if (((param_1 & 2) == 0) || (iVar3 = FUN_40146f9c(1,8), iVar3 == 0)) goto LAB_400e83ec;
          uVar8 = func_0x40085c04();
          uVar4 = FUN_401847ec("02X%02X");
          uVar5 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
          uVar7 = 0x507;
          pcVar6 = "A! %d\r\n";
        }
        else {
          uVar8 = func_0x40085c04();
          uVar4 = FUN_401847ec("02X%02X");
          uVar5 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
          uVar7 = 0x500;
          pcVar6 = "e! %d\r\n";
        }
      }
      else {
        uVar8 = func_0x40085c04();
        uVar4 = FUN_401847ec("02X%02X");
        uVar5 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
        uVar7 = 0x4f9;
        pcVar6 = "e! %d\r\n";
      }
    }
    else {
      if (DAT_3ffc518c == '\0') {
        FUN_400e78c8();
      }
      iVar3 = FUN_400e7928(0,&DAT_3ffc518c);
      if (iVar3 == 0) goto LAB_400e8312;
      uVar8 = func_0x40085c04();
      uVar4 = FUN_401847ec("02X%02X");
      uVar5 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
      pcVar6 = "i! %d\r\n";
      uVar7 = 0x4f3;
    }
    FUN_4012105c(pcVar6,uVar5,uVar4,uVar7,"iFiStop",iVar3);
    bVar1 = 0;
  }
  return bVar1;
}

