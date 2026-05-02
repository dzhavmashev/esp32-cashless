// Function : FUN_4014b4e4
// Address  : 0x4014b4e4
// Size     : 230 bytes


void FUN_4014b4e4(int param_1,char *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    if (*param_2 == -0x23) {
      param_2 = param_2 + 4;
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x80;
      memw();
    }
    else if (DAT_3ffc89ee != '\x01') {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x40;
    }
    *(undefined2 *)(param_1 + 0x15c) = *(undefined2 *)(param_2 + 2);
    memw();
    *(char *)(param_1 + 0x15e) = param_2[4];
    memw();
    bVar1 = param_2[5];
    memw();
    (*(code *)&SUB_4008b3d0)(&uStack_30,"11_ht.c",0x10);
    if (bVar1 < 0x81) {
      *(undefined1 *)(param_1 + 0x2f2) = 1;
      memw();
    }
    if ((char)bVar1 < '\0') {
      uVar2 = 0x90;
      if ((*(uint *)(param_1 + 0xc) & 0x18000) == 0) {
        memw();
        uVar2 = uStack_2f;
      }
    }
    else {
      uVar2 = 0;
    }
    *(undefined1 *)(param_1 + 0x2ee) = uVar2;
    memw();
    memw();
    return;
  }
  FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x625);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

