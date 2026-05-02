// Function : FUN_4010a484
// Address  : 0x4010a484
// Size     : 168 bytes


undefined4 FUN_4010a484(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0x3ffc5d50;
  iVar5 = 0;
  do {
    if ((*(char *)(iVar6 + 0x1e) == '\x03') &&
       (iVar2 = FUN_4018529c(param_1,iVar6 + 0x24,0x100), iVar2 == 0)) {
      if (*(char *)(iVar6 + 0x18) == '\x06') {
        bVar1 = true;
        if ((param_3 & 0xfffffffd) != 1) {
          bVar1 = false;
        }
      }
      else {
        bVar1 = (param_3 & 0xfffffffd) != 1;
      }
      if (bVar1) {
        uVar3 = 0;
        if (param_2 != (undefined4 *)0x0) {
          *(char *)(param_2 + 5) = *(char *)(iVar6 + 0x18);
          memw();
          iVar5 = iVar5 * 0x128;
          if ((&DAT_3ffc5d68)[iVar5] == '\x06') {
            *param_2 = *(undefined4 *)(iVar5 + 0x3ffc5d54);
            param_2[1] = *(undefined4 *)(iVar5 + 0x3ffc5d58);
            param_2[2] = *(undefined4 *)(iVar5 + 0x3ffc5d5c);
            param_2[3] = *(undefined4 *)(iVar5 + 0x3ffc5d60);
            *(undefined1 *)(param_2 + 4) = *(undefined1 *)(iVar5 + 0x3ffc5d64);
            memw();
          }
          else {
            uVar4 = *(undefined4 *)(iVar5 + 0x3ffc5d54);
            param_2[3] = 0;
            *param_2 = uVar4;
            param_2[2] = 0;
            param_2[1] = 0;
            *(undefined1 *)(param_2 + 4) = 0;
            memw();
            memw();
          }
        }
        goto LAB_4010a4f8;
      }
    }
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x128;
    if (iVar5 == 4) {
      uVar3 = 0xf0;
LAB_4010a4f8:
      memw();
      return uVar3;
    }
  } while( true );
}

